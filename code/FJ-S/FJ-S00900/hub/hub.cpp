#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd(){
	int x=0,f=1;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}return x*f;
}
int c,t,n,k,u,v;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	c=rd();t=rd();
	while(t--){
		n=rd();k=rd();
		for(int i=1;i<=n;i++){
			u=rd();v=rd();
		}
		if(n==k)cout<<0<<"\n";
		else if((n-1)/2<=k){
			cout<<1<<'\n';
		}else{
			cout<<((n-1)/2-k)/4+(((n-1)/2-k)%4!=0)+1<<'\n';
		}
	}
	return 0;
}
