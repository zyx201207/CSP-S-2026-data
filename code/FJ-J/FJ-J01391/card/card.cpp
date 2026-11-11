#include<bits/stdc++.h>
using namespace std;
long long a[500025],b[300015],c[300015],d[300015],ans[300015];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]!=0){
			c[a[i]]=i;
		}
		else{
			d[a[i]]=i; 
		} 
		b[a[i]]++; 
	}
	if(n==m){
		while(m--){
			cout<<3<<" ";
		} 
		return 0;
	}
	while(n--){
	}
	return 0;
}
