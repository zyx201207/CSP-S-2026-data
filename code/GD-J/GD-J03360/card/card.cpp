#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int p[N],ans[N],a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int len=0;
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			if(p[a[j]]!=0){
				int tmp=0,tmp1=p[a[j]];
				for(int k=1;k<=m;k++){
					if(tmp1<=p[k]&&p[k]<=len){
						p[k]=0;
						tmp++;
					}
				}
				len=len-tmp+1;
				p[a[j]]=len;
			}
			else{
				p[a[j]]=++len;
			}
		}
		for(int j=1;j<=m;j++){
			if(p[j]!=0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
