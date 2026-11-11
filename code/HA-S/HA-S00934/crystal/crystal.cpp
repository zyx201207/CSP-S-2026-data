#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0,sum=1,q=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt=a[2]-a[1];
	q=cnt;
	for(int i=1;i<=n-1;i++){
		if(q<=m){
			sum++;
			m-q;
			q=q+cnt*sum;
		}
	}
	cout<<sum;
	return 0;
}
