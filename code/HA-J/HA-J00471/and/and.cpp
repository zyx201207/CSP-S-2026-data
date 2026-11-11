#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[200005][35],len[200005],sum,cnt;
stack<int>b;
void rjz(int n){
	while(n>0){
		int a=n%2;
		b.push(a);
		n/=2;
	}
}
void y(int x,int y,int i,int j,int k){
	c[i+1][k]=x&y;
}
void sjz(long long n,int j){
	sum=1;
	for(int i=1;i<=j;i++){
		sum*=2;
	}
	cnt+=sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		rjz(a[i]);
		len[i]=b.size();
		for(int j=1;j<=len[i];j++){
			c[i][j]=b.top();
			b.pop();
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=len[i],k=len[i+1];j>=1,k>=1;j--,k--){
			y(c[i][j],c[i+1][j],i,j,k);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=len[i];j>=1;j--){
			int k=0;
			sjz(c[i][j],k);
			k++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
} 
