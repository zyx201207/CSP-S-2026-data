#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n]={};
	int sum=0;
	int b,d;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=n;j>0;j++){
			if(a[i]<a[i+1]||a[j]>a[i-1]){
				sum++;
				b=a[i];
				d=a[j];
			}
		}
	}
	cout<<sum<<b<<d;
	return 0;
}