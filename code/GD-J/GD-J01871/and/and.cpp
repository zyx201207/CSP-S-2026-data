#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],flg=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,c,maxn=-2e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]+1)flg=0;
	}
	if(flg){
		cout<<0<<endl;
		return 0;
	}else{
		cout<<a[1]<<endl;
	}
	return 0;
} 


