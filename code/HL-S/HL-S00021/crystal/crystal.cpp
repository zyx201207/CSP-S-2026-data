#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ma,b[500005],k=1,aa;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		if((i-k+1)*a[i]-b[i]+aa<=m){
			ma=i-k+1;
		}else{
			aa+=a[k++];
		}
	}
	cout<<ma;
	return 0;
}