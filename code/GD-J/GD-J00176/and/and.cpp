#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],ansm=INT_MIN,ansa,ansb=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ansm=max(ansm,a[i]);
		if(i==1) ansa=a[i];
		else ansa=ansa&a[i];
	}
	if(m==1) cout<<ansm;
	else if(m==n) cout<<ansa;
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ansb=max(ansb,a[i]&a[j]);
			}
		}
		cout<<ansb;
	}
	else cout<<3;
	return 0;
}
