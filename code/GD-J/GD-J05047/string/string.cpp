#include<bits/stdc++.h>
using namespace std;
struct Ac{
	long long a;
	char c;
}s[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	long long ans=0;
	int l=1,r=n;
	while(l<r){
		if(s[l].c==s[r].c){
			if(s[l].a==s[r].a){
				l++;
				r--;
			}
			else if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}
			else{
				s[r].a-=s[l].a;
				l++;
			}
		}
		else{
			if(s[l].a==s[r].a){
				ans+=s[l].a;
				l++;
				r--;
			}
			else if(s[l].a>s[r].a){
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}
			else{
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}
		}
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
