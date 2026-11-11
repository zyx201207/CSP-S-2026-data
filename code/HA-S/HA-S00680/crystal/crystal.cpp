#include <bits/stdc++.h>
using namespace std;
int c[10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,d;
	int count=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c+0,c+n);
	for(int i=0;i<n;i++){
		if(m>0){
			d = c[n/2]-c[i];
			c[i]+=d;
			m-=d;
		}
	}
	for(int i=0;i<n;i++){
		if (c[i]==c[n/2]){
			count ++;
		}
	}
	
	cout<<count<<endl; 
	return 0;
} 
