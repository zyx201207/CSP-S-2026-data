#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 50010;
const int MAXM = 30010;

int n,m;
int a[MAXN];
int res[MAXN];

signed main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	bool is_ordered=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])is_ordered=false;
	}
	if(is_ordered){
		int buc[MAXM]={};
		for(int i=1;i<=n;i++){
			buc[a[i]]++;
		}
		int k=0;
		for(int i=1;i<=m;i++){
			k+=buc[a[i]];
			cout<<k<<' ';
		}
	}
	return 0;
}

