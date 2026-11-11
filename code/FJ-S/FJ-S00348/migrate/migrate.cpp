#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000001];
bool dc=1;
inline int rd(){
	int k=0,q=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')q=-1;
		c=getchar();
	}while(isdigit(c)){
		k*=10,k+=c-48,c=getchar();
	}return k*q;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--){
		int n=rd(),d=rd();
		for(int i=1;i<=n;++i){
			a[i]=rd();	
		}for(int i=1;i<=n;++i){
			if((a[i]-a[i-1]!=a[i+1]-a[i])&&(i>=2)&&(i<n))dc=0;
		}
		if(dc){
			int gc=a[n]-a[n-1],fl=1;
			if(a[1]<=0){
				for(int i=1;i<=n;++i){
					a[i]-=a[1],a[i]+=gc;
				}
			}//cout<<a[1]<<endl;
			else gc=a[1]-gc;
			for(int i=1;i<=n;i++){
				a[i]-=gc;
			}if(d<gc){
				cout<<0<<'\n';fl=0;
			}if(!fl)continue;
			gc=a[1];
			d/=gc;
			a[n]/=gc;
			if(d>=a[n]/2+1)cout<<0<<'\n';
			else{
				d*=2;
				cout<<a[n]-d+1<<'\n';
			}
		}else cout<<"0\n";
	}
	return 0;
}