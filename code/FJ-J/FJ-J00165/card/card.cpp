#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,a[N],ans[300010], b[300010],c[300010],tmp[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ;i <= n ;i++) {
		scanf("%d",&a[i]);
	}
	for(int i = 1 ;i <= n;i++) {
		for(int i = 1 ;i <= m ;i++) {
			b[i]=c[i]=0;
		}
		for(int o = 1 ;o <= n ;o++) {
			tmp[o] = a[o];
		}
		for(int j = i;j<=n;j++) {
			if(b[tmp[j]] != 0 ) {
				for(int k = b[tmp[j]];k < j;k++) {
					c[tmp[k]] --;
					b[tmp[k]] = 0;
					tmp[k] = 0;
				}
				b[tmp[j]] = j;
				c[tmp[j]] ++;
			}else{
				b[tmp[j]] = j; 
				c[tmp[j]] ++;
			}
		}
		for(int i = 1 ;i <= m ;i++) {
			if(c[i]) {
				ans[i] ++;
			}
//            cout<<c[i]<<" ";
		}
//		cout<<endl;
	}
	for(int i = 1 ;i <= m ;i++) {
		printf("%d ",ans[i]);
	}
	return 0;
} 
