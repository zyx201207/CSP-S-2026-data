#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,u=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++) b[i]=a[i]-a[i-1];
	for(int i=1;i<n;i++){
		if(s<m) s+=b[i],u++;
		else break;
	}
	cout<<u;
	return 0;
}
