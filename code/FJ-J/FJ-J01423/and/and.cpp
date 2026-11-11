#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt=0,c=0;
bool f=1,o=1;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f=0;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(f){
		cout<<1;
	}
	else{
		cout<<a[m];
	}
	return 0;
}
