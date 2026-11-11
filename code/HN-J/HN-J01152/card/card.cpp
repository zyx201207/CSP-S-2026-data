#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 5e5+5;
int n,m,p[MAX_N],z[MAX_N],chu[MAX_N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		chu[p[i]]=i;
	}
	for(int i=1;i<=m-1;i++){
		cout<<chu[i]<<" ";
	}
	cout<<chu[m]; 
	return 0;
}
