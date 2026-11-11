#include<bits/stdc++.h>
using namespace std;
int const N=2*1e6;
int a[N],z[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1; i<=t; i++){
		int n,d;
		cin>>n>>d;
		for(int j=1; j<=n; j++){
			cin>>a[j];
		}
		int sum=0;
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(abs(a[k+1]-a[j])>=d && (a[k+1]-a[j])%d!=0){
					sum++;
				}
			}
			
		}
		z[i]=sum;
	}
	for(int i=1; i<=t; i++){
		cout<<z[i]<<endl;
	}
}
