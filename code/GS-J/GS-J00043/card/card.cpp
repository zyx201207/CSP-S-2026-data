#include<iostream>
#include<cstring>
#define int long long
using namespace std;
const int N=5e5+1,M=3e5+1;
int n,m;
int a[N];
int st[N],top=0;
bool tong[N];
int ans[N];
void push(int x){
	st[++top]=x;
	return ;
}
void pop(){
	top--;
	return ;
}
int front(){
	return st[top];
}
bool empty(){
	return !top;
}
void init(){
	top=0;
	memset(tong,false,sizeof tong);
	return ;
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;i++){
		init();
		for (int j=i;j<=n;j++){
			if (!tong[a[j]]){
				push(a[j]);
				tong[a[j]]=true;
			}
			else{
				while (front()!=a[j]){
					tong[front()]=false;
					pop();
				}
				tong[front()]=false;
				pop();
				push(a[j]);
				tong[a[j]]=true;
			}
		}
		for (int j=1;j<=m;j++){
			if (tong[j]==true) ans[j]++;
		}
	}
	for (int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	printf("\n");


	return 0;
}

