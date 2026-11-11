#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N],c[N],maxn=-1,maxa=-1,d=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		maxa=max(maxa,a[i]);
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--){
		a[d++]=b[i];
		if(d==n){
			break;
		}
	}
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		c[i]=(c[i-1]&a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=n;j-m>=0;j--){
			maxn=max(maxn,(c[i]&c[j-m-1]));
		}
	}
	cout<<maxn;
	return 0;
} 
