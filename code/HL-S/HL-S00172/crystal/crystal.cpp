#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l,n,m,a[10001],ans[10001];
bool c(int y){
	return (a[y]*(y-1)-ans[y-1]<=m)
}
int main ()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]+a[i];
	}
	l left=0,right=n-1,mm;
	while(l<r){
		mm=(l-r)>>1;
		if(c(mm)){
			l=mm+1;
		}else{
			r=mm;
		}
	}
	for(int i=1;i<=n;i++){
	}
	cout<<mm<<endl;
	return 0;
}
