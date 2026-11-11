#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],s[i];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<s[a[i]]<<endl;
	}
	return 0;
} 


