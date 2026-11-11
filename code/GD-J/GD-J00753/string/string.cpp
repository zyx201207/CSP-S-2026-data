#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=2000005;
int n;
ll ans;
struct node{
	ll a;
	char c;
}s[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	for(int l=1,r=n;l<=r;){
		if(s[l].c==s[r].c){
			if(s[l].a==s[r].a) l++,r--;
			if(s[l].a<s[r].a) s[r].a-=s[l].a,l++;
			if(s[l].a>s[r].a) s[l].a-=s[r].a,r--;
		}
		else{
			if(s[l].a==s[r].a){
				ans+=s[l].a;
				l++;
				r--;
			}
			if(s[l].a<s[r].a){
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}
			if(s[l].a>s[r].a){
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}
		}
	}
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//string
