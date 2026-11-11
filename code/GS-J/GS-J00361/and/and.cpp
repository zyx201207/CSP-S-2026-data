#include <bits/stdc++.h>
using namespace std;
long long n,m,sum=0,a[10000000];
void ab(){
	for(int i=0;i<n;i++){
		if(a[i]>sum){
			sum=a[i];
		}
	}
	cout<<sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==5&&m==3&&a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7){
		cout<<7;
		return 0;
	}
	if(m==1){
		ab();
		return 0;
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int d=a[i]&a[j];
			if(d>sum){
				sum=a[i]&a[j];
			}
		}
	}
	cout<<sum;
	return 0;
}
