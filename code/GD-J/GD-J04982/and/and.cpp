#include<bits/stdc++.h>
using namespace std;
int n,m,s,maxx;
map<int,int> a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[s]=a[s]+1;
		if(a[s]>=m&&maxx<=s)maxx=s;
	}cout<<maxx;
	
	return 0;
}
