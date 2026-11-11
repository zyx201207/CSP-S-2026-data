#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m;
bool a[200005][33];
ll pow_2[34],ans;
bool book[200005];
int maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	pow_2[0]=1;
	for(int i=1;i<=31;i++){
		pow_2[i]=pow_2[i-1]*2;
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) book[i]=1;
	
	int t;
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		int l=0;
		while(t){
			a[i][l]=t%2;
			t/=2;
			l++;
		}
		maxx=max(maxx,l);
	}
	for(int i=maxx;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(!book[j]) continue;
			if(a[j][i]) sum++;
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(!a[j][i]) book[j]=0;
			}
			ans+=pow_2[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
