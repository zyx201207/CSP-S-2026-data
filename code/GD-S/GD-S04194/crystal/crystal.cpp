#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		if(a[i]=a[i]+1){
			a[i]+=1;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
