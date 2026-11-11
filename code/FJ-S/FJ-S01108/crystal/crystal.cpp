#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,m;
	int ma=-100000000;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ma<a[i])ma=a[i];
	}
	int maa=1;
	for(int i=1;i<=ma;i++){
		int cz=m;
		int k=0;
		for(int j=0;j<n;j++){
			if(a[n-j]<=i&&cz-i+a[n-j]>=0){
				cz-=i-a[n-j];
				k++;
			}
			
		}
		if(k>maa)maa=k;
	}
	cout<<maa;
	return 0;
}
