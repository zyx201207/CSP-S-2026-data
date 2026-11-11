#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[200010],k=LLONG_MIN;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
			cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		if(i!=j){
		    k=max(k,a[i]&a[j]);
		}
	}
	}	
	cout<<k;
		return 0;
}
