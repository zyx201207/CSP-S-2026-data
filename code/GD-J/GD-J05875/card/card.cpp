#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int a[5*maxn];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=m;o++){
		int cnt=0;
		for(int i=o;i<=m;i++){
			bool it1=0,it2=0;
			for(int j=1;j<=i;j++){
				if(a[j]==i) it1=1;
			}
			for(int j=i+1;j<=n;j++){
				if(a[j]==i) it2=1;
			}
			if(it1==1&&it2==1) cnt++;
		}
		cout<<cnt<<' ';
	}
	return 0;
} 
