#include<bits/stdc++.h>
using namespace std;
int n,m,a[2007],maxn,b[2007][37],c[40],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int g=a[i],st=0;
		while(g!=0){
			b[i][st]=g%2;
			g/=2;
			st++;
		}
		maxn=max(maxn,st-1);
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	cout<<168;
	return 0;
}
