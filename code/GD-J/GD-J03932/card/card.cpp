#include<bits/stdc++.h>
using namespace std;
bool y[300010];
int n,m,a[500010],b[300010],c[300010];//c【i】为总出现次数 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int x = 1;x <= n;x++){
		int top = 0;
		for(int i = x;i <= n;i++){
			if(!y[a[i]]){	
				b[++top] = a[i];
				y[a[i]] = true;
			}else{
				while(b[top] != a[i]){
					y[b[top]] = false;
					top--;
				}
			}
		}
		for(int i = 1;i <= top;i++){
//			printf("%d ",b[i]);
			c[b[i]]++;
			y[b[i]] = false;
		}
//		printf("\n");
	}
	for(int i = 1;i <= m;i++)
		printf("%d ",c[i]);
}
//Trick||Treat!
