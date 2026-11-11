#include <bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=3e5+3;
int n,m,cnt,t[N],a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		cnt=0;
		for(int j=i;j<n;j++){
			int tp=a[j];
			for(int k=0;k<cnt;k++){
				if(tp==t[k]){
					cnt=k;
					break;
				}
			}
			t[cnt++]=tp;
		}
		for(int j=0;j<cnt;j++)ans[t[j]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
}
