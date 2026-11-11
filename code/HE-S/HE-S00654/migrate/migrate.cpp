#include <bits/stdc++.h>
using namespace std;
const int N=1e8;
long long c,t,n,d,x[N],sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		cin>>n>>d;
		for(int i=1; i<=n; i++){
			cin>>x[i];
		}
		for(int i=n; i>=1; i--){
			for(int j=1; j<=i-1; j++){
				if(x[i]-x[j]<=d && x[i]-x[j]!=1){
					sum++;
				}
			}
		}
		if(sum-1<=2){
			cout<<sum-1<<" ";
		}
		else{
			cout<<0;
		}
		sum=0;
		cout<<endl;
		t--;
	}
	return 0;
} 	
