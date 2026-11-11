#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct Node{
	long long x,y;
}a[200005];
int check(long long n){
	int sum=0;
	while(n){
		sum+=n%2;
		n/=2;
	}
	return sum;
}
bool cmp(Node a,Node b){
	if(a.y==b.y)return a.x>b.x;
	return a.y>b.y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].y=check(a[i].x);
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].x;
	for(int i=2;i<=m;i++){
		ans&=a[i].x;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
