#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],pos[N],ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int x=1;x<=n;x++){
		memset(b,0,sizeof(b));
		memset(pos,0,sizeof(pos));
		int now=0;
		for(int i=x;i<=n;i++){
			if(pos[a[i]]){
				int _now=pos[a[i]]-1;
				for(int j=pos[a[i]];j<=now;j++){
					pos[b[j]]=0;
				}
				now=_now;
			} 
			b[++now]=a[i];
			pos[a[i]]=now;
		}
		for(int i=1;i<=now;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d",ans[i]);
		if(i!=m) printf(" ");
	}
	return 0;
}
