#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],a1[N],p2[100],v[N][100]={},sum[100]={};
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) a1[i]=a[i];
	int x=1,len=-1;
	for(int i=0;i<=30;i++){
		p2[i] = x;
		x *= 2;
	}for(int i=1;i<=30;i++){
		if(a[1] < p2[i]){
			len = i-1;
			break;
		}
	}for(int i=1;i<=n;i++){
		for(int j=len;j>=0;j--){
			if(a1[i] >= p2[j]){
				v[i][j] = 1;
				a1[i] -= p2[j];
			}
		}
	}int l=1,r=n;
	for(int i=len;i>=1;i--){
		int cnt=0;
		for(int j=l;j<=r;j++){
			if(v[j][i]==1) cnt++;
		}if(cnt>=m){
			sum[i]=1;
			r = cnt;
		}
	}int f=0;
	for(int i=30;i>=0;i--){
		if(f==0&&sum[i]==0) continue;
		f=1;
		cout<<sum[i];
	}
	return 0;
} 







