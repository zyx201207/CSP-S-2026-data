#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum=sum*i;
	}
	long long sum1=1;
	for(int i=1;i<=m;i++){
		sum1=sum1*i;
	}
	long long sum2=1;
	for(int i=1;i<=n-m;i++){
		sum2=sum2*i;
	}
	int x=sum/(sum1*sum2);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			b[i]=a[i]&a[j];
		}
	}
	sort(b+1,b+x+1);
	cout<<b[x];
	return 0;
}