#include<bits/stdc++.h>
using namespace std;

long long a[1000000]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n , m , i , j , x=0 , v=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		x+=a[i];
	}
	long long mid=x/2;
	cout<<n;
} 
