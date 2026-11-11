#include <bits/stdc++.h>
using namespace std;

int n,m,a[5010],b[5010],s[3010],x,y,t,q = 1;

int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool l;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
for(int k = 1;k <= n;k++){		
	for(int i = 1;i <= n;i++)
		b[i] = 0;
	for(int i = k;i <= n;i++){
		l = false;
		x = a[i];
		for(int j = 1;j <= n;j++){
			if(x == b[j]){
				l = true;
				y = j;
			}
		}
		if(l == false){
			b[q] = x;
		}else {
			for(int j = y + 1;j <= q;j++)
				b[j] = 0;
			q = y - 1;
		}
		q++;
	}
	for(int j = 1;j <= q;j++)
		s[b[j]]++;
}
	for(int i = 1;i <= m;i++)
		printf("%d ",s[i]);
	
	return 0;
}


