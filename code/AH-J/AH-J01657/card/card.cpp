#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 300005
using namespace std;
stack<int> s;
int a[MAXN];
bool b[MAXM];
int c[MAXM];
bool f=1; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i-1]>a[1])f=0;
	}
	if(f==1){
		for(int i=1;i<n;i++)if(a[i+1]>a[i])printf("%d ",i);
		printf("%d",n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				s.push(a[j]);
				b[a[j]]=1;
			}
			else while(s.top()!=a[j]){
				b[s.top()]=0;
				s.pop();
			}
		}
		for(int i=1;i<=m;i++)c[i]+=b[i],b[i]=0;
		while(!s.empty())s.pop();
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	return 0;
} 
