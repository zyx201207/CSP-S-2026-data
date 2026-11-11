#include<bits/stdc++.h>
using namespace std;
const int A=5e5+5,B=3e5+5;
int a[A],mk[B],ans[B];
int n,m;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(mk,0,sizeof(mk));
		for(int j=i;j<=n;j++){
			if(mk[a[j]]){
				for(int k=mk[a[j]];k<j;k++)mk[a[k]]=0;
				cout<<j;
			}
			mk[a[j]]=j;
		}
		for(int j=i;j<=n;j++)if(mk[a[j]])ans[a[j]]++;
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
