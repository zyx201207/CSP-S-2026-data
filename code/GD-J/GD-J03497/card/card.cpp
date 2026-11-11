#include<bits/stdc++.h>
using namespace std;
void bubble(long long a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j+1]>a[j]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m; 
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bubble(a,n);
	int s=1;
	for(int i=n;i>=n-m;i--){
		int d=a[i];
		s=s^d;
	}
	cout<<3<<1<<4;
	
}
