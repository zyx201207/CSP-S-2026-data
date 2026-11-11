#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
pair<int,char> s[MAXN];
ll ans=0;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	
	int l=1,r=n;
	while(l<r){
		int a=max(s[l].first,s[r].first),b=min(s[l].first,s[r].first);
		
		if(s[l].second==s[r].second){
			if(a==b){
				l++,r--;
				continue;
			}
			else{
				int maxx;
				if(a==s[l].first) maxx=l;
				else maxx=r;
				s[maxx].first-=b;
				if(maxx==l) r--;
				else l++;
			}
		}
		else{
			if(a==b){
				ans+=a;
				l++,r--;
				continue;
			}
			else{
				int maxx;
				if(a==s[l].first) maxx=l;
				else maxx=r;
				ans+=b;
				s[maxx].first-=b;
				if(maxx==l) r--;
				else l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
