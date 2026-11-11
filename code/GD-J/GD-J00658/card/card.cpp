#include<bits/stdc++.h>
using namespace std;
int a[500005],m,n,cnt[300005],sum[300005];
bool flag;
string T;
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		T="";
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++){
			if(!cnt[a[j]]){
				T+=char(a[j]+'0');
				cnt[a[j]]++;
			}
			else{
				flag=0;
				for(int k=T.size();0<=k;k--){
					if(T[k]-'0'==a[j]) flag=1;
					if(!flag && T[k]!='/'){
						cnt[T[k]-'0']--;
						T[k]='/';
					}
				}
			}
		}
		for(int j=0;j<T.size();j++) sum[T[j]-'0']++;
	}
	for(int i=1;i<=m;i++) printf("%d ",sum[i]);

	return 0;
}
