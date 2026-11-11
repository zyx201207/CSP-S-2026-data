#include<bits/stdc++.h>
using namespace std;
long long n,m,dz;
long long a[500005];
long long dp[500005];
long long dx[5005][5005];
long long gs[5005][5005];
bool bj1=1,bj2=1;
void work(){
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		dp[i-1]=a[i]-a[i-1];
	}
//	for(int i=2;i<=n;i++){
//		cout<<dp[i-1]<<" ";
//	}
//	cout<<"\n";
	long long best=1;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
//			cout<<"dx[i,j-1]: "<<dx[i][j-1]<<"\n";
			dx[i][j]=dx[i][j-1]+dp[j-1]*(j-i);
//			cout<<i<<" "<<j<<" "<<dx[i][j]<<"  ";
			if(dx[i][j]>m){
				break;
			}else{
				gs[i][j]=j-i+1;
				if(best<gs[i][j])best=gs[i][j];
//				cout<<"\n";
//				cout<<"best: "<<i<<" "<<j<<" "<<gs[i][j]<<"\n";
			}
		}
//		cout<<"\n";
	}
	cout<<best;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","d",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=a[i])bj1=0;
		if(i==2)dz=a[2]-a[1];
		if(i>2){
			if(a[i]-a[i-1]!=dz)bj2=0;
		}
	}
	if(bj1){
		long long x=0;
		int xx=0;
		for(int i=1;i<=n&&x<=m;i++){
			x+=i;
			xx++;
		}
		cout<<xx;
		return 0;
	}
	if(bj2){
		long long x=0;
		int xx=0;
		for(int i=1;i<=n&&x<=m;i++){
			x+=i*dz;
			xx++;
		}
		cout<<xx;
		return 0;
	}
	work();
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/
