#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int o=0;
	if(n%2==0){
		o=n/2;
	}else{
		o=n/2+1;
	}
	long long b=a[o];
	int j=1;
	while(b-a[o-j]<=m){
		m-=b-a[o-j];
		a[o-j]=b;
		j++;
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(a[i]==b){
			t++;
		}
	}
	cout<<t;
	return 0;
}
