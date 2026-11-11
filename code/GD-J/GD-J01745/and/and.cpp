#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],sum=0,d=0;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	int i1,j1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>d){
				d=a[i]&a[j];
				i1=i,j1=j;
			}
		}
	}
	a[i1]=0;
	a[j1]=0;
	for(int i=1;i<=m-2;i++){
		int b[200005];
		for(int j=1;j<=n;j++){
			b[j]=d&a[j];
		}
		sort(b+1,b+n+1);
		d=d&b[n];
	}
	cout<<d;
	return 0;
}
