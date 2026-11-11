#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,sum;
struct node{
	int a;
	char b;
}s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		sum+=s[i].a;
	}int last=0,lasts=n,sx=0;
	for(int i=1;last<=sum/2+s[i].a;i++){
		int t=0;
		for(;lasts>i;lasts--){
			if((t+s[lasts].a)>s[i].a){
				if(s[lasts].b!=s[i].b){
					ans+=(s[i].a-t);
				}s[lasts].a=s[lasts].a-(s[i].a-t);
				break;
			}
			t+=s[lasts].a;
			if(t==s[i].a){
				if(s[i].b!=s[lasts].b){
					ans+=s[lasts].a;
				}lasts--;
				break;
			}else{
				if(s[lasts].b!=s[i].b){
					ans+=s[lasts].a;
				}
			}sx=0;
		}last+=s[i].a;
	}cout<<ans;
	return 0;
}
