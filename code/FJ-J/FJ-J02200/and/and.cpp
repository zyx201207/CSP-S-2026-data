#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	long long n,m,max1=-1,max=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=max){
			max=a[i];
			max1=i;
		}
	}
	for(int i=1;i<=m;i++){
		long long s;
		s=max;
		max=-1;
		for(int j=1;j<=n;j++){
			if((s&a[j])>=max&&j!=max1){
				max=(s&a[j]);
			}
		}
	}
	cout<<max;
	return 0;
}
