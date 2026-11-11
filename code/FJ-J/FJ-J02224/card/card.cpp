#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],c[500010];
vector<int>b(500010);

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){	
			for(int k=0;k<=n;k++){
				if(b[k]==a[j]){
					for(int l=k;l<=n;l++){
						b.pop_back();
					}
				}
			}
			b.push_back(a[j]); 
		}
		int ok=1;
		for(int j=0;j<=n;j++)
			if(b[j]==i){
				ok=0;
				break;
			}
		if(ok==0)c[i]++;
		b.clear();
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	return 0;
}
