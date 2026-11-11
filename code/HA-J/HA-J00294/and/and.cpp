#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,a[100000],c=-1e5;
    cin>>n>>m;
    for(int i=0;i<n;++i){
    	cin>>a[i];
    }
	for(int i=0;i<n;++i){
    	c=max(c,(a[i]&a[i-1]));
    }
    cout<<c;
	return 0;
}
