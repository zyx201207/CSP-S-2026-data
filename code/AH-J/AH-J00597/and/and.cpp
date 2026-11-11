#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn;
int cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		cout<<maxn;
		return 0;
	}
	if(m==3){
		sort(a+1,a+1+n,cmp);
		cout<<a[3];
		return 0;
	}
    return 0;
}
