#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[2050],sum1=0;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
    }
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++){
			int sum=a[i];
			for(int k=i+1;k<=j;k++){
				sum=sum&a[k];
			}
			sum1=max(sum1,sum);
		}
	}
	cout<<sum1;
}
