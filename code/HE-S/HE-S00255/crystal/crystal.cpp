#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={0},x,q[500005]={0};
long long maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q[i]=a[i]+q[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			x=a[i]*(i-j)-(q[i-1]-q[j-1]);
			if(x<=m){
				if(maxx<(i-j+1)){
					maxx=(i-j+1);
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
