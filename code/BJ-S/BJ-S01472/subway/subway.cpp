#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,sum=0,d,c,t,x[500001]={};
 	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int a=1;a<=n;a++){
			cin>>x[a];
		}
		for(int a=1;a<=n-3;a++){
			if((x[a+1]-x[a]<=d&&x[a+3]-x[a+1]<=d)&&(x[a+2]-x[a]<=d&&x[a+3]-x[a+2]<=d)){
				if(n-4>=a){
					if(x[a+4]-x[a]>=d){
						sum++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
