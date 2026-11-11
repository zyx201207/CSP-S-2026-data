#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long cnt[30];
int n,m;
long long a[N];
long long ans;
int c[30][N];
int f[N];
int q;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cnt[0]=1;
    for(int i=1;i<=29;i++) cnt[i]=cnt[i-1]*2;
    cin>>n>>m;
	for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        for(int j=29;j>=0;j--){
        	if(a[i]>=cnt[j]){
        		c[j][i]=1;
        		if(a[i]==cnt[j]) j=0;
        		a[i]-=cnt[j];
			}
		}
	}
	for(int i=29;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(f[j]==q&&c[i][j]==1){
				sum++;
				++f[j];
			}
		}
		if(sum>=m) ans+=cnt[i];
		else{
			for(int j=1;j<=n;j++){
				if(f[j]==q) ++f[j];
			}
		}
		++q;
	}
	printf("%lld",ans);
    return 0;
}
