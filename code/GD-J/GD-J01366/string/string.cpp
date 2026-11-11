#include<bits/stdc++.h>
using namespace std;
int n,x,k,k1,ans;
char a,s[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&x);
		scanf("%s",&a);
		for(int j = 1; j <= x; j++){
			s[k++] = a;
		} 
	}
	for(int i = k - 1; i >= k / 2; i--){
		if(s[k1++] == s[i]) ans ++;
	}
	//printf("%d",ans);
	int l = (k + 1) / 2 - ans;
	printf("%d",l);
	return 0;
}
