#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;cin>>n;
	long long m;cin>>m;
	long long a[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int z=a[n/2+1];
	int sum=0;
	for(int i=1;i<=n/2+1;i++){
		if(m>=z-a[i]){
			sum++;
			m-=z-a[i];
		}
	}
	for(int i=n/2+2;i<=n;i++){
		if(a[i]==z){
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
