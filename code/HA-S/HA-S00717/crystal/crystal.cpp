#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(m>=(a[i+1]-a[1])){
			m-=(a[i+1]-a[i]);
			a[i]=a[i+1];
			i-=2;
		}else{
			cout<<i;
			return 0;
		}
	}return 0;
}
