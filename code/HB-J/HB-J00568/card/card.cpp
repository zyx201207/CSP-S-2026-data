#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m;
int a[2*N],book[N],ans[N],flag[2*N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}for(int i=n;i>=1;--i){
		if(book[a[i]]!=0){
			for(int j=i+1;j<book[a[i]];++j){
				if(flag[j]==0){
					book[a[j]]=0;
					flag[j]=1;
				}
			}
		}else{
			book[a[i]]=i;
		}for(int j=1;j<=m;++j){
			if(book[j]!=0) ans[j]++;
		}
	}for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}

	return 0;
}
