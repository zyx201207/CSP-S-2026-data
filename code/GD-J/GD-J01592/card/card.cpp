#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N],ans[N],last[N];//last j最后的位置 
bool crd[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(crd,0,sizeof crd);
		memset(last,0,sizeof last);
		int k=0;
		for(int j=i;j<=n;j++){
			if(crd[a[j]]==1){
				for(int z=last[a[j]];z<j;z++){
					k--;
					crd[a[z]]=0;
				}
				crd[a[j]]=1;
				last[a[j]]=j;
				k++;
			}else{
				last[a[j]]=j;
				crd[a[j]]=1;
				k++;
			}
		}
		for(int j=1;j<=m;j++){
			if(crd[j]==1){
				ans[j]++;	
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
