#include<bits/stdc++.h>
using namespace std;
int a[505050],vis[505050],tot[505050];
struct st{
	int v[505050],tp=0;
	void push(int x){
		v[tp++]=x;
	}
	void pop(){
		tp--;	
	}
	int top(){
		return v[tp-1];
	}
	void clear(){
		tp=0;
	}
	void write(){
		for(int i=0;i<tp;i++){
			printf("%d ",v[i]);
		}
		putchar('\n');
	}
};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	st s;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]) vis[s.top()]=0,s.pop();
				//printf("#666#");
			}else{
				s.push(a[j]);
				vis[a[j]]=1;
			}
			//s.write();
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) tot[i]++;
			vis[i]=0;
		}
		s.clear();
	}
	for(int i=1;i<=m;i++){
		printf("%d ",tot[i]);
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
