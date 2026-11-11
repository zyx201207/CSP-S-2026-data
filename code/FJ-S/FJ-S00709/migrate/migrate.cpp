
#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[1000098];
void chhh(){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		int cut=0,num=0,a=d*d,b=0;
		for(int z=1;z<=n-3;z++){
			b=z+a;
			cut=0;
			for(int v=z+1;v<=n-1&&x[v]<=b;v++){
				if(x[v]-x[z]<=d){ 
					cut++;
				}
			}
			if(cut==2){
				num++;
			}
		}
		cout<<num<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		chhh();
	}
	return 0;
}
		
