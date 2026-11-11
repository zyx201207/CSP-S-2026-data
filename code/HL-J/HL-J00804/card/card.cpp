#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e5+10;
ll n,m,a[N],k[M],last[M];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++)
			last[i]=0;
		for(int j=i;j<=n;j++){
			if(last[a[j]]!=0){
				for(int k=last[a[j]];k<=j;k++){
					last[a[k]]=0;
				}
			}
			last[a[j]]=j;
		}
		for(int i=1;i<=m;i++)
			if(last[i]) k[i]++;
	}
	for(int i=1;i<=m;i++){
		cout << k[i] <<' ';
	}
	return 0;
}