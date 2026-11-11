#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x=unique(a+1,a+n+1)-(a+1);
	if(m==1){
		cout<<a[x];
		return 0;
	}
	
	return 0;
}

