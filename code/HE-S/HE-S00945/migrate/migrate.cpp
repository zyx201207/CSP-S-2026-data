#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				sum=(a[i]-a[j])/d+1;
			}
		}cout<<sum<<endl;
	}
	return 0;
}
