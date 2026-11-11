#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,cnt=0;
int a[500009],b[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==1){
		c=a[n/2+1];
	}else{
		c=a[n/2];
	}
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-c);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]<=m){
			cnt++;
			m-=b[i];
		}
	}
	cout<<cnt;
	return 0;
}
