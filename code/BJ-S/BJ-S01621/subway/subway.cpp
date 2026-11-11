#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int f[N],g[N],n,sum;
char s[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(s[i]=='S')f[i]=f[i-1]+1;
		else f[i]=0;
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='S')g[i]=g[i+1]+1;
		else g[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='S'){
		ans=max(ans,f[i-1]+g[i+1]+1);
		}else{
		ans=max({ans,f[i-1],g[i+1]});
		}
	}
	cout<<ans<<endl;
	return 0;
}