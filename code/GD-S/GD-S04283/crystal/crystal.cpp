#include <bits/stdc++.h> 
using namespace std;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m;
int a[500005];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k=a[0];
	for(int i=0;i<n;i++){
		if(a[i]<k){
			k=a[i];
		}
	}
	int sum=n;
	for(int i=0;i<n;i++){
		if(a[i]-k>m){
			sum--;
		}
	}
	cout<<sum<<endl;
	return 0;
}
