#include<bits/stdc++.h>
using namespace std;
int a[300000],n,m,smax=-1,b[300000],s,c[300000],z=0;
void dp(int cnt){
	if(cnt==m+1){
		s=b[1];
		for(int j=2;j<=m;j++){
			s=s&b[j];
		}
		smax=max(smax,s);
		return;
	}
	for(int i=z+1;i<=n;i++){
		z=i;
		b[cnt]=a[i];
		cnt++;
		dp(cnt);
		cnt--;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp(1);
	cout<<smax;
	return 0;
}
