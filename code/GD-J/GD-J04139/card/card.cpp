#include<bits/stdc++.h> 
using namespace std;
int a[500005];
int nmax=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=nmax){
			nmax=a[i];
		}
	}
	if(nmax=a[n]){
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
	}
	return 0;
}
