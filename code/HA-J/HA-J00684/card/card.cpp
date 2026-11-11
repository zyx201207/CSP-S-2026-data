#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[500005],m,k;
int c[300005][3];
int ans[300005];
bool ch;
struct aaa{
	int x,y;
}b[300005];
bool cmp(aaa q,aaa w){
	return q.x<w.x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
 		scanf("%d",&a[i]);
 		if(c[a[i]][1]!=0){
 			b[++k].x=c[a[i]][2];
			b[k].y=i;
			c[a[i]][1]=0;
		}else{
			c[a[i]][1]++;
			c[a[i]][2]=i;
		}
	}
	sort(b+1,b+k+1,cmp);
	int st=1;
	for(int l=1;l<=n;l++){
		for(int i=1;i<=k&&ch==0;i++){
			if(l>b[st].x){
				st++;
				if(st>k){
					ch=1;
					break;
				}
			}else{
				break;
			}
		}
		int la=l;
		if(ch){
			for(int j=l;j<=n;j++){
				ans[a[j]]++;
			}
			continue;
		}
		for(int j=la;j<b[st].x;j++){
			ans[a[j]]++;
		}
		for(int i=st+1;i<=k;i++){
			if(b[i-1].y<la){
				continue;
			}
			for(int j=b[i-1].y;j<=b[i].x;j++){
				ans[a[j]]++;
			}
			la=b[i].y;
		}
		for(int j=b[k].y;j<=n;j++){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
}
//172.16.12.5
