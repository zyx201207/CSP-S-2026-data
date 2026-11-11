#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int qwe;
	cin>>qwe; 
	int c,t;
	cin>>c>>t;
	int n,d;
	int a[2000000];
	for(int i=0;i<t;i++){
		int sum=0;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=3;j<n;j++){
			if(a[j]-a[j-3]>d&&a[j]-a[j-3]<2*d){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
