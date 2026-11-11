#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],t[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		fill(t,t+n+1,0);
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				for(int k=t[a[j]]+1;k<j;k++){
					t[a[k]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(t[j]){
				ans[j]++;
//				cout<<j<<" ";
			}
		}
	}
//	cout<<"\n";
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}


