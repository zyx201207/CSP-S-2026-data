#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,t,z;
	cin>>n>>m;
	int a[n]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i+1]<a[i]){
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
    z=a[n/2];
	for(int i=1;i<=m;i++){
		while(a[i]==z){
			if(m==0){
				break;
			}
			else{
				a[i]++;
				m--;
			}
		}
		if(a[i]==z){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
