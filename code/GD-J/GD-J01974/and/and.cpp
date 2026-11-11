#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]<a[j+1]){
				long long fg=a[j];
				a[j]=a[j+1];
				a[j+1]=fg;
			}
		}
	}
	long long sum=a[0];
	for(int i=1;i<=m;i++){
		sum=(sum&a[i]);
	}
	cout<<sum;
	
	return 0;
}
