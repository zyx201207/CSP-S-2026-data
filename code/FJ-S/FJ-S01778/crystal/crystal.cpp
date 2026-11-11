#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mins=0,min=1000000000001,max=-1000000000001,max1=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<min){
			min=a[i];
		}
		if(a[i]>max){
			max=a[i];
		}
	}
	for(long long j=1;j<=m;j++){
		b[j]=a[j];
		for(long long m1=m;m1>0;m1--){
			int m2=m;
			min=1000000000001;
			mins=0;
			max=0;
			for(long long i=1;i<=n;i++){
				if(b[i]<min){
					mins=i;
					min=b[i];
				}
				if(b[i]>max){
					max=b[i];
				}
			}
			b[mins]++;
			m2--;
		}
		int jsq;
		for(int j=1;j<=max;j++){
			jsq=0;
			for(int i=1;i<=n;i++){
				if(b[i]==j){
					jsq++;
				}
			}
			if(jsq>max1){
				max1=jsq;
			}
		}
	}

	cout<<max1-1;
	return 0;
}
