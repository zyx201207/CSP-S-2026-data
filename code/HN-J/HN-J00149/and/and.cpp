#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+7;
int a[maxn];
int idx,r[maxn][33];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=31;j>=0;j--){
			bool t=(a[i]&(1<<j));
			r[i][j]=r[i-1][j]+t;
		}
	}
	int sum=0,maxj=31,l=0;
	while(n>=m){
		int flag=1,tmp=0;
		for(int i=1;i<=n;i++){
			if(r[i][maxj]==0) tmp=i;
			else break;
		}
		if(tmp!=n) l=tmp;
		for(int j=maxj;j>=0;j--){
			if(r[n][j]-r[l][j]>=m){
				n=l+r[n][j]-r[l][j];
				maxj=j-1;
				sum+=(1<<j);
				flag=0;
				break;
			}
		}
		if(flag) break;
	}
	cout<<sum;
	return 0;
}
