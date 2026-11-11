#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int a[N];
int n,m;
int cnt[N];
int p[N];
int h;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		h=1;p[h]=a[i];
		for(int j=i+1;j<=n;j++){
			bool f=1;
			for(int k=1;k<=h;k++){
				if(f){
					if(p[k]==a[j]){
						h-=(j-k);
						f=0;
					}
				}	
			}
			p[++h]=a[j];
		}
		for(int j=1;j<=h;j++)cnt[p[j]]++;
	} 
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
