#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long sum=0,ans=0;
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x=a[(n+1)/2];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){	
			if(a[i]+j==x){
				m=m-j;
				a[i]=a[i]+j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
