#include<bits/stdc++.h>
using namespace std;
int n,m,a[2008],s[2008][16],maxi=-5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int j=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxi=max(maxi,a[i]);
		while(a[i]>1){
			j++;
			s[i][j]=a[i]%2;
			a[i]/=2;
		}
	}
	if(m==1){
		cout<<maxi;
		return 0;
	}
	return 0;
}
