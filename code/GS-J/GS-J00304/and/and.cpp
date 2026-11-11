#include<cstdio>

using namespace std;

int m,n,max = 0,a[200000 + 10];

void dfs(int step,int b,int m1){
	if(step == n + 1){
		if(m1 > max) max = m1;
		return ;
	}
	for(int i = b ; i <= m ;i ++){
		if(step == 1) m1 = a[i];
		dfs(step + 1,i + 1,a[i] & m1);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i = 1;i <= m;++ i){
		scanf("%d",&a[i]);
	}
	
	dfs(1,1,a[1]);
	
	printf("%d",max);
	
	return 0;
}

