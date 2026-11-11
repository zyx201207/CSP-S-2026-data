#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int s,t;
	cin>>s>>t;
	for(int g=1;g<=t;g++){
		int n,m;
		cin>>n>>m;
		int bj=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
					bj=0;
				}
			}
		}
		int o=0;
		if(bj==1){
			if(n>=4)o+=n-3;
			if(n<2*m)o++;
		}
		cout<<o<<endl;
	}
	return 0;
}
