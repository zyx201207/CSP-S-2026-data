#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],s[300009],z[500009],t=0,ans[500009];
bool x = 1;
//10 3
//3 1 2 1 3 2 3 1 2 1
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		ans[a[i]]=i;
		if(a[i] < a[i-1]){
			x=0;
		}
	}
	if(x){
		for(int i = 1;i <= m;i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	for(int i = 1;i <= m;i++){
		ans[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(s[a[j]]>0){
				for(int k = s[a[j]]+1;k <= t;k++){
					s[z[k]]=0;
					z[k]=0;
				}
				t = s[a[j]];
			}
			else{
				t++;
				s[a[j]]=t;
				z[t]=a[j];
			}
		}
		for(int j = 1;j <= n;j++){
			ans[z[j]]++;
			z[j]=0;
			s[j] = 0;
		}
		t=0;
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
