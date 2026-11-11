#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[10000][10000],c=0,l=1,r;
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i][1]=a[i+1]-a[i];
	}
	for(int i=2;i<n;i++){
		for(int j=i;j<n;j++){
			b[j][i]=b[j][i-1]+b[j-1][i-1]-b[j-1][i-2];
		}
	}
//	for(int i=1;i<n;i++){
//		for(int j=1;j<n;j++){
//			cout<<b[j][i]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=n-1;i>=1;i--){
		l=0;
		r=1;
		while(l<=m&&r<=i){
			l+=b[i][r];
			r++;
		}
		if(l>m){
			l-=b[i][r-1];
			r--;
		}
//		cout<<l<<" "<<r<<endl;
		c=max(c,r);
	}
	cout<<c;
	return 0;
}

