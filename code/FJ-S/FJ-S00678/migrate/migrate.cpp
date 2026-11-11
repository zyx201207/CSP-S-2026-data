#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],o,p;
void sr(long long q,long long z,long long v){
	if(v>p){
		return ;
	}
	if(q==z){
		if(v<p){
			o=1;
			p=v;
		}else{
			o++;
		}
		return ;
	}
	for(long long i=q+1;i<=z;i++){
		if(x[i]-x[q]<=d){
			sr(i,z,v+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long v=1;v<=t;v++){
		cin>>n>>d;
		long long u=0;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				p=n;
				sr(i,j,0);
				if(o==2){
					u++;
				}
				o=0;
			}
		}
		cout<<u<<"\n";
	}
	return 0;
}
