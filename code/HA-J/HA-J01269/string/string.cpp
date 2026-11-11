#include<bits/stdc++.h>
#define int long long
using namespace std;
string ds;
int dn,dns,d[200010];
char dc[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>dn;
	for(int i=1;i<=dn;i++){
		cin>>d[i]>>dc[i];
		for(int j=1;j<=d[i];j++){
			ds+=dc[i];
		}
	}
	for(int i=0;i<=(ds.size()-1)/2;i++){
		if(ds[i]!=ds[ds.size()-i-1]) dns++;
	}
	cout<<dns<<'\n';
	return 0;
}
