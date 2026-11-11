//GZ-J00624 毕节梁才学校  赵纤茹
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000+10];
bool v[300000+10];
int cnt[300000+10];

int stk[500000+10];
int tt=-1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		tt=-1;
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(tt==-1||!v[a[j]]) stk[++tt]=a[j],v[a[j]]=true;
			else if(v[a[j]]){
				while(tt>=0&&stk[tt]!=a[j]) v[stk[tt]]=false,tt--;
			}
		}
		for(int k=0;k<=tt;k++){
			cnt[stk[k]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
} 
