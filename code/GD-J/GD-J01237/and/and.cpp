#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,x,y,a[35][200005],b[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	while(n--){
		scanf("%lld",&x),i=x,j=0;
		while(i){
			if(i%2==1)a[j][++a[j][0]]=x;
			i/=2,j++;
		}
	}
	for(i=29;i>=0;i--)
		if(a[i][0]>=m){
			ans+=(1<<i);
			for(j=1;j<=a[i][0];j++)b[j]=a[i][j];
			n=a[i][0];
			memset(a,0,sizeof a);
			for(j=1;j<=n;j++){
				x=b[j],y=0;
				while(x){
					if(y>=i)break;
					if(x%2==1)a[y][++a[y][0]]=b[j];
					x/=2,y++;
				}
			}
		}
	printf("%lld",ans);
	return 0;
}
