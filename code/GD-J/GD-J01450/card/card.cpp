#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10 , M = 3e5 + 10;
int n , m , a[N],ig[N],k[N],pd[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(pd,-1,sizeof pd);
		memset(k,-1,sizeof k);
		for(int j=i;j<=n;j++){
			if(pd[a[j]] == -1) k[j] = a[j],pd[a[j]] = j;
			else {
				for(int u=pd[a[j]];u<=j;u++) k[u] = -1,pd[a[u]] = -1;
				k[j] = a[j];
				pd[a[j]] = j;
			}
		}
		for(int j=i;j<=n;j++){
			//cout<<k[j]<<" ";
			if(k[j]!=-1) ig[k[j]]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ig[i]<<" ";
	return 0;
}
