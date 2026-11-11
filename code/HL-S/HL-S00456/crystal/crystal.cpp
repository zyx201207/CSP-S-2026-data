#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int n,m,ans;
int a[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int flag = 1;
	sort(a + 1,a + 1 + n);
	for(int i = 2;i <= n;i++){
		int cnt = m;
		for(int j = 1;j < i;j++){
			 if(cnt - (a[i] - a[j]) < 0){
			 	flag = 0;
			 	break;
			 }
			 else{
			 	cnt = cnt - (a[i] - a[j]);
			 }
			 
		}
		if(flag == 0){
			ans = i - 1;
			break;
		}
	}
	printf("%d",ans);
	
}