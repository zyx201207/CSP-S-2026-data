#include <bits/stdc++.h>
using namespace std;

int n,m,a[2010],b[20],s[20],v = 10,q,p = 1,x;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool l = false;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	if(m == 1){
		for(int i = 1;i < n;i++)
			if(a[i] > a[i + 1]){
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		printf("%d",a[n]);
		return 0;
	}
	if(m == n){
		for(int i = 1;i <= n;i++){
			q = a[i];
			for(int j = 10;j >= 1;j--){
				 b[j] = q % 2;
				 q = q / 2;
			}
			if(l == false){
				for(int j = 10;j >= 1;j--)
					s[j] = b[j];
				l = true;
			}else{
				for(int j = 10;j >= 1;j--){
					if(b[j] == s[j] && b[j] == 1){
						s[j] = 1;
					}else
						s[j] = 0;
					}
 			}
		}
	for(int i = 1;i <= 10;i++){
		l = true;
		p = 1;
		if(s[i] != 0)
			l = false;
		if(l == false){
			for(int j = 1;j <= v;j++)
				p = p * 2;
			if(s[i] == 1)
				x = x + p;
			v--;
		}
	}
	printf("%d",x);	
}
}
