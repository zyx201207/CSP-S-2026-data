#include<bits/stdc++.h>
using namespace std;
int a[200005],sum,max1 = -9999;
int b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[0];
	sum = a[0];
	for(int i = 1;i < n;i++){
		cin>>a[i];
		sum&=a[i];
		max1 = max(max1,a[i]);
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==1){
		cout<<max1;
		return 0;
	}
	max1 = -9999;
	if(m==2){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j<n;j++){
				max1 = max(max1,a[i]&a[j]);
			}
		}
		cout<<max1;
		return 0;
	}
	if(m==3){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k < n;k++){
					max1 = max(max1,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<max1;
		return 0;
	}
	return 0;
}
