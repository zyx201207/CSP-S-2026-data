#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,ans;
int x[200010];
string s;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		x[i]=a;
		s[i]=c;	
	}
	for(int i=1,q=n;i<=q,q>=i; ){
		if(i==q) break;
		if(x[i]==0) i++;
		if(x[q]==0) q--;
		if(s[i]!=s[q]) ans+=min(x[i],x[q]);
		if(x[i]>=x[q]){
			x[i]-=x[q];
			x[q]=0;
		}else{
			x[q]-=x[i];
			x[i]=0;
		}	
	}
	cout<<ans;
	return 0;
}
