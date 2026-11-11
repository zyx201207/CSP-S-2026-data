#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int cnt[300010];
int l[500010]={};
bool f[300010]={};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof l);
		int cur=0;
		for(int j=i;j<=n;j++){
			int pos=0;
			for(int k=1;k<=cur;k++){
				if(l[k]==a[j]){
					pos=k;
					break;
				}
			}
			if(pos){
				cur=pos;
			}else{
				l[++cur]=a[j];
			}
		}
		memset(f,0,sizeof f);
		for(int j=1;j<=cur;j++){
			f[l[j]]=true;
		}
		for(int j=1;j<=m;j++){
			cnt[j]+=f[j];
		}
	}
	
	for(int i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

