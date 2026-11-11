#include <bits/stdc++.h>
using namespace std;
int a[2*100000+3];
//bool cmp(int x,int y){
//	if(x&2==0 && y&2==0){
//		return x>y;
//	}else if(x&2==0 && y&2==1){
//		return x>y;
//	}else if(x&2==1 && y&2==0){
//		return y>x;
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	long long cnt=0;
	for(int i=1;i<m;i++){
		cnt+=a[i]||a[i+1];
	}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
