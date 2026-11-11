#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool fx=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)
		{
			fx=false;
		}
	}
	if(!(fx)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	long long num=0;
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<i;j++){
			num=num+a[i]-a[j];
			a[j]=a[i];
		}
		if(num>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
