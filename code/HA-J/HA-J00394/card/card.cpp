#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],q[N],wher[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int pls=1;
	while(pls<=n){
		int top=0;
		for(int i=pls;i<=n;i++){
			int findi=-1;
			for(int j=1;j<=top;j++){
				if(q[j]==a[i]){
					findi=j;
					break;
				}
			}
			if(findi==-1){
				q[++top]=a[i];
				wher[a[i]]=top;
			}else{
				top=findi;
				wher[a[i]]=top;
			}
		}
		for(int i=1;i<=top;i++){
			//cout<<q[i]<<" ";
			cnt[q[i]]++;
		}
		pls++;
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
