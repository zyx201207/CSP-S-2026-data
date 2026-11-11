#include<bits/stdc++.h>
using namespace std;
long long n,m,q;
long long a[100000000],c[100000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		if(m<=0){ 
			continue;
		}
		else if(m>0){
			m=m-c[i];
			q++;
		}
	}
	cout<<q;
}
