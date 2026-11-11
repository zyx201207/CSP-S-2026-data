#include<bits/stdc++.h>
using namespace std;

const int N=5e5+3,M=3e5+3;
bool special_A=true;
int n,m;
int a[N];
int ans[M];
int lst[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) special_A=false;
		lst[a[i]]=i;
	}
	if(special_A){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1])
				ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
			printf("%d ",ans[i]);
	}else{
		for(int i=n;i>=1;i--){
			if(lst[a[i]]==0)
				lst[a[i]]=i;
		}
		for(int i=n;i>=1;i--){
			for(int j=i;j<=n;){
				ans[a[j]]++;
				j=lst[a[j]]+1;
			}
		}
		for(int i=1;i<=m;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}
