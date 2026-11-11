#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b,cnt=1,a1[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i = 0;i<n;i++){
		if(i==0)a1[i]=a[i];
		else a1[i]=a1[i-1]+a[i];
	}
	for(int i =1;i<n;i++){
		b=a[i]*(i+1)-a1[i];	
		if(b>m){
			break;
		}
		else{
			cnt++;
		}	
	}
	cout<<cnt;
	return 0;
}
