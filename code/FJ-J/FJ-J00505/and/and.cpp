#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,sum,res,a[N],b[100],c[100][N],d[N];
int lowbit(int x){
	return -x&x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int p=a[i];
		while(p){
			int q=lowbit(p);
			p-=q;
			int w=log2(q)+1;
			c[w][i]=a[i];
			b[w]++;
		}
	}
	for(int i=80;i>=1;i--){
		if(b[i]>=m){
			sum=i;
			res+=pow(2,i-1);
			for(int j=1;j<=n;j++) d[j]=c[sum][j];
			break;
		}
	}
	for(int i=sum-1;i>=1;i--){
		int flag=0;
		for(int j=1;j<=n;j++){
			if(c[i][j]&&d[j]) flag++;
		}
		if(flag>=m){
			res+=pow(2,i-1);
			for(int j=1;j<=n;j++) d[j]=(d[j]&&c[i][j]);
		}
	} 
	cout<<res;
	return 0;
}
