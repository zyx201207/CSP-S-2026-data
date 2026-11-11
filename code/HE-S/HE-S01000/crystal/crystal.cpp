#include<bits/stdc++.h>
using namespace std;
int n,m,a[100009],s,o;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s=1;
	for(int i=1;i<n;i++){
		o=(a[i+1]-a[i])*i;
		if(o<=m){
			m-=o;
			s++;
		}
	}
	cout<<s;
} 
