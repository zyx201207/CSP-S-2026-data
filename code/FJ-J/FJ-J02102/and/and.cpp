#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],c[200005],id;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]){
				c[i]++;
			}
		}
		if(c[i]>d){
			d=c[i];
			id=i;
		}
	}
	if(d>=m){
		cout<<a[id];
	}else{
		sort(a+1,a+1+n);
		cout<<a[n/2+1];
	}
	return 0;
}
