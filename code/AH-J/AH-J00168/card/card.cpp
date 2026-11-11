#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,W=3e5+10;
int n,m,a[N];
long long r[W]={0},t[W][2]={{0}};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
		cin>>a[i];
	for(int i=n; i>=1; --i){
		t[a[i]][0]++;
		if(t[a[i]][0]==2){
			for(int j=i; j<t[a[i]][1]; ++j){
				t[a[j]][0]--;
			}
		}
		t[a[i]][1]=i;
		for(int j=1; j<=m; ++j)
			r[j]+=t[j][0] ;
	}
	for(int i=1; i<=m; ++i)
		cout<<r[i]<<" ";
    return 0;
}
