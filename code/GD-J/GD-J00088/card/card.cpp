#include<bits/stdc++.h>
using namespace std;
int a[N],fl[N],ans[N];
const int N=5e5+5;
int cheak(int k,int j){
	for(int i=k+1;i<=j;i++){
		for(int w=k;w<i;w++){
			if(a[i]==a[w]){
				for(int q=k;q<=w;q++){
					fl[q]=0;
				}
				k=w;
			}
		}
	}
	return k;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		memset(fl,1,sizeof(fl));
		int k=check(i,n);
		for(int j=k;j<=n;j++){
				ans[a[i]]+f[k];
		}
	}
	for(int i=1;i<=m)
	return 0;
}

