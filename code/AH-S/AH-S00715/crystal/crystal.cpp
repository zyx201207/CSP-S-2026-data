#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001]={},s=0,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		t=abs(a[i+1]-a[i]);
		if(m<0){
			cout<<s;
			return 0;
		}
		s++;
		m-=i;
	}
	cout<<m/n+s;
	return 0;
}
