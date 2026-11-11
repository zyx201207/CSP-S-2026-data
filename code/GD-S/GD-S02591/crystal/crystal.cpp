#include<bits/stdc++.h>
using namespace std;
int main(){
		ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int sum=0;
		if(a[i]>a[i+1]){
			sum=a[i];
			a[i]=a[i+1];
			a[i+1]=sum;
		}
		}
	int mid=0;
	if(n%2==0){
		mid=a[n/2];
	}
	else{
		mid=a[(n)/2];
	}
	int b;
	for(int i=0;i<m+1;i++){
		
		if(a[i]<mid){
			b=mid-a[i];
			a[i]=mid;
			m-=b;
		}

	}
	int num=1;
	for(int i=0;i<n;i++){

		if(a[i]==a[i+1]){
			num++;
		}
	}
cout<<num;
	
	return 0;
}


