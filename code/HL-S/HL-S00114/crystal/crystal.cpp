#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long sum=0;
	long long a[5000000]={0}; 
	for(int i=1;i<=n;i++){
		cin>>n;
	}
	for(int i=1;i<=m;i++){
		if(a[i]*i==a[i+1]*(m-i)){
			long long t=a[i]*i==a[i+1]*(m-i);
			if(t==a[i+2]){
				sum++;
			}
		}
	}
	cout<<sum;
	
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
