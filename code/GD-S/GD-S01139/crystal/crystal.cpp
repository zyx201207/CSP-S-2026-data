#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n;
	long long int m;
	long long int a[100005];
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}		
	for(int i=1;i<=n;i++){
		a[i]+=1;
		for(int j=i;j<=m;j++){
		if(a[i]==a[n]){
			cnt++;
		}
	}
}
	cout<<cnt;
	return 0;
} 
