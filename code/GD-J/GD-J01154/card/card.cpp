#include <bits/stdc++.h>

using namespace std;

int n=0,m=0,ans[300005]={0},a[500005]={0},q[500005],b[300005]={0},t[300005]={0};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	
	for(int i=1;i<=n;i++){
		int w=0;
		for(int j=1;j<=n;j++){
			t[j]=b[j];
		}
		
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(t[k]==b[k]){
				w++;
				q[w]=k;
				t[k]--;
			}else{
				for(int l=1;l<=w;l++){
					if(q[l]==k){
						w=l;
						break;
					}
				}
			}
		}
		
		for(int j=1;j<=w;j++){
			ans[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	
	return 0;
}
