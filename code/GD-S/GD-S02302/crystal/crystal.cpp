#include <bits/stdc++.h>
using namespace std;

int n,m,sum,a[500001];

int main(){
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		int x=m,y=1;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<=x){
				x-=a[i]-a[j];
				y++;
			}else{
				break;
			}
		}
		cout << y;
		if(y>sum){
			sum=y;
		}
	}
	cout << sum;
	
	return 0;
} 
