#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[100005];
	cin>>n>>m;
	long long max[100005]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		long long maxid=0;
		for(int j=1;j<=n;j++){
			if(a[j]>max[i]){
				max[i]=a[j];
				maxid=j;
			}
			a[maxid]=0;
		}
	}
	long long sum=max[1];
	for(int i=2;i<=m;i++){
		sum=(sum&max[i]);
	}
	cout<<sum;
	return 0;
}
