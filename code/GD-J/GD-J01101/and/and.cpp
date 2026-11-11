#include<bits/stdc++.h>
using namespace std;

int a[200010],n,m,mx;
void serch(int number,int sum,int cnt){
	sum=sum&a[number++];
	cnt++;
	if(cnt==m){
		if(sum>mx) mx=sum;
		return;
	}
	for(int i=number;i<=n;i++) serch(i,sum,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++) serch(i,a[i],0);
	cout<<mx;
	return 0;
}
