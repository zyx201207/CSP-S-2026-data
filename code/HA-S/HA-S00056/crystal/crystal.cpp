#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum,maxx=-1;
int a[500009],b[500009],c[500009];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		int hp=m,num=1;
		for(int j=i-1;j>=1;j--){
			if(b[i]-b[j]<=hp){
				hp-=(b[i]-b[j]);
				num++;
//				cout<<c[j]<<" "<<c[i-1]<<endl;
			}else break;
		}
		maxx=max(maxx,num);
	}
	cout<<maxx;
	return 0;
} 

