#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010],t;
int c[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		set<int> st;
		for(int j=i;j<=n;j++){
			if(st.count(a[j])){
				bool f=0;
				int tmp=t;
				for(int k=1;k<=t;k++){
					if(b[k]==a[j]){
						f=1;
						tmp=k;
					}
					if(f){
						st.erase(b[k]);
						b[k]=0;
					}
				}
				t=tmp;
			}
			st.insert(a[j]);
			b[++t]=a[j];
		}
		for(int j=1;j<=t;j++){
			c[b[j]]++;
			b[j]=0;
		}
		t=0;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",c[i]);
	}
    return 0;
}
