#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,n1[500001],m1[300001]={};
    cin>>n>>m; 
    for(int i=0;i<n;i++){
    	cin>>n1[i];
    	m1[n1[i]]++;
	}
	m1[n1[n-1]]=n;
	for(int i=0;i<n;i++){
		cout<<m1[i]<<' '; 
	}
	return 0;
}
