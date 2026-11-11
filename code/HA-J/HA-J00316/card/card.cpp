#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int n,m,si;
int a[N];
int num[N];
int v[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;++i){
		for(int k=1;k<=si;++k){
			v[k]=0;
		}
		si=0;
		for(int j=i;j<=n;++j){
			int add=a[j];
			int id=0;
			for(int k=1;k<=si;++k){
				if(v[k]==add){
					id=k;
					break;
				}
			}
			if(v[id]==add){
				for(int k=1;k<=si;++k){
					v[k]=0;
				}
				si=0;
			}
			si++;
			v[si]=add;
		}
		for(int j=1;j<=si;++j){
			num[v[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<num[i]<<' ';
	}
	return 0;
}

/*
不就是接竹竿吗？awa 
*/
