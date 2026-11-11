#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100001],b[100001],cnt,maxn[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	k=m;	
	for(int i=n,j=1;i>0;i--,j++){
		if(k==0)break;
		maxn[j]=a[i];
		k--;
	}
	cnt=maxn[1];
	for(int i=2;i<=m;i++){
		cnt=cnt&maxn[i];	
	}
	cout<<cnt;

	return 0;
}
