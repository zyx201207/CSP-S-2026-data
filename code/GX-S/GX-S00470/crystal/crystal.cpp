#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0;
	long long m=0;
	int sum=0;
	int temp=0;
	int r=0;
	int sum2=0;
	int sumall=0;
	int sumall2=0;
	int q=0;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(1<2){
		if(sum==n){
			break;
		}
		else{
			sum=0;
			for (int j=0;j<n;j++){
				if(a[j]>a[j+1]){
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
				else sum++;
			}
		}
	}
	while(q<n){
		if(q<=n){
			q++;
			for(int w=0;w<=q;w++){
				sum2=a[q]-a[q-w];
			}
		}
		sumall+=sum2;
		if(sumall==sumall2){
			r=q;
			break;
		}
		sumall2=sumall+sum2+1;
	}
	cout<<r-1;
	return 0;
}
