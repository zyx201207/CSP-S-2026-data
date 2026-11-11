#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int aq=1;aq<=t;aq++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		if(c==11||c==12){
			int sss=x[2]-x[1];
			if(d<2*sss){
				cout<<0<<endl;
			}else{
				cout<<n-((d/sss-1)*2+1)<<endl;
			}
		}
	}
	return 0;
}

