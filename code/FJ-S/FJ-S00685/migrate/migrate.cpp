#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int c,t,n,d;
bool b[N];
long long zx,x[N],y[N];
int f(int w,int z){
	int s=0;
	if(w>=y[w]) return 0;
	if(y[w]>=z) return 1;
	if(!b[y[w]]) b[y[w]]=1,s+=f(y[w],z);
	if(s>2) return 3;
	if(w>=y[w]-1) return s;
	if(!b[y[w]-1])
		b[y[w]-1]=1,s+=f(y[w]-1,z);
	if(s>2) return 3;
	return s;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,zx=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
			y[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				fill(b+1,b+n+1,0);
				if(f(i,j)==2) zx++;
			}
		}
		cout<<zx<<"\n";
	}
	return 0;
}
