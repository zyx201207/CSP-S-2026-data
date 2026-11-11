#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int sum=0,num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			if (a[i]+1==a[sum]){
				a[i]=a[i]+1;
				num++;
			}
			if (a[i]==a[sum]){
				num++;
			}
			sum++;
			
		}
	}
	cout<<num;
	return 0;
} 
