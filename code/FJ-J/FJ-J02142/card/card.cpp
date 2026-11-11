#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],t[300009],ans[300009],nt[500009];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])f=0;
		nt[t[a[i]]]=i;
		t[a[i]]=i;
	}if(f){
		for(int i=1;i<=m;i++){
			t[i]=0;
		}for(int i=n;i>=1;i--){
			if(!t[a[i]]){
				t[a[i]]=1;
				ans[a[i]]=i;
			}
		}for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(nt[j]!=0)j=nt[j];
			else ans[a[j]]++,j++;
		}
	}for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
