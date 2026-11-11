#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ma=0;
bool cmp(long long a,long long b){
	return a>b; 
}
long long an(long long ai,long long ii){
	m--;
	for(int i=ii+1;i<=n;i++){
		long long x=ai&a[i];
		if(m==1){
			ma=max(ma,x);
		}
		else{
			an(x,i);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		an(a[i],i);
	}
	cout<<ma;
	return 0;
}
