#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],c[31][200010],D,e[200010];
long long check(){
	long long maxn=0,cc=1,ans=1;
	e[cc]=m;
	for(int i=31;i>=1;i--){
		if(c[i][m]==1){
			for(int j=1;j<=n;j++){
				if(c[i][j]==1&&j!=m){
					cc++;
					e[cc]=j;
				}
				if(cc==m){
					break;
				}
			}
			if(cc==m){
				cc=m;
				break;
			}else{
				cc=1;
			}
		}
	}
	if(cc<m){
		return 0;
	}
	for(int i=1;i<=30;i++){
		for(int j=1;j<=cc;j++){
			ans=1&c[i][e[j]];
			if(ans==0){
				break;
			}
		}
		maxn+=ans*pow(2,i-1);
	}
    return maxn;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=31;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=a[j]%2;
			a[j]=a[j]/2;
		}
	}
	cout<<check();
	return 0;
}

