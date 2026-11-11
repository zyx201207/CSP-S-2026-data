#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[600000];
int b[400000];
int c[400000];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		//for(int j=1;j<=m;j++)c[i]=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==1){
				int k=j-1;
				while(a[j]!=a[k]&&k>=i){
					c[a[k]]=0;
					k--;
				}
			}else c[a[j]]++;
//			for(int j=1;j<=m;j++){
//				cout<<c[j]<<" ";
//			}cout<<endl;
		}//cout<<endl;
		for(int j=1;j<=m;j++){
			if(c[j]!=0)b[j]++;
			//cout<<c[j]<<" ";
		}//cout<<endl;
		for(int j=1;j<=m;j++)c[j]=0;
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}


