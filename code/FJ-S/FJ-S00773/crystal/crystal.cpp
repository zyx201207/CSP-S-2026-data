#include<bits/stdc++.h>
using namespace std; 
long long n,m,cnt,x;
long long a[1000005],d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	d=a[1]-a[0];
	x=d;
	while(m>=0&&n>0){
		if(m-x>=0)cnt++;
		n--;
		m-=x;
		x+=d;
	}
	cout<<cnt;
	return 0;
}
