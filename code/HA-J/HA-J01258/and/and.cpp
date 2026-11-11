#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=-999;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n); 
	if(m==1){
		cout<<a[n-1];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int n=(a[i]&a[j]);
				if(n>=sum) sum=n; 
			}
		}
	}
	cout<<sum;
	return 0;
}
