#include <bits/stdc++.h>
using namespace std;
int a[500005];
int j[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
        cin>>a[i];
        j[a[i]]++;
	}
	if(m==1){
		for(int i=1;i<=m;++i){
			cout<<"1"<<" ";
		}
	}
	if(m==2){
		for(int i=1;i<=m;++i){
			cout<<j[i]<<" ";
		}
	}
	return 0;
} 
