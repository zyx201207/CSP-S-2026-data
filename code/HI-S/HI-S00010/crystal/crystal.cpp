#include <bits/stdc++.h>
using namespace std;
int b[100005],a[100005],c[10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,L=1,R=2,nm=0,nm1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];//差值
		c[i]=c[i-1]+b[i];//差值的和 
	}
	while(R<=n){
		if(c[R]-c[L]<m){
			R++;
			nm1=R-L;
			if(nm1<nm)break;
			else nm=max(nm,nm1);
		}
		else {
			L++;
		}
	}
	cout<<nm;
	return 0;
}

