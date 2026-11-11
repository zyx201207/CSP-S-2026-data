#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
    long long n,m,a[2005],b[2005],c[2005];
    vector<long long>d;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i]; 
    	c[a[i]]++;
	}
	
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
