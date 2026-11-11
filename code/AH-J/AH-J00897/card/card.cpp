#include<bits/stdc++.h>
using namespace std;
long long n,m,t[300010],a[500010],b[500010],h=0,ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(b,0,sizeof(b));
		h=0;
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(t[x]==0){
				t[x]++;
				b[++h]=x;
			}
			else{
				long long k=j-1;
				while(b[k]!=x){
					t[b[k]]--;
					b[k]=0;
					k--;
				}
				t[b[k]]--;
				b[k]=0;
				t[x]++;
				b[++h]=x;
			}
		}
		for(int j=1;j<=h;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)  printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}
