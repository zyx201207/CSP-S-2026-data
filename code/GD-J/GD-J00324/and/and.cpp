#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n=0,m=0,l=0,bi=0,f=0;
	cin>>n>>m;
	int a[99999]={};
	for(int i=0;i<n;i++){
		cin>>l;
		if(l>bi) bi=l;
		a[l]++;
	}
	int b[m]={},s=m;
	for(int i=bi;i>0;i--){
		if(a[i]==0) continue;
		for(int j=0;j<a[i];j++) b[--m]=i;
	}
	long long ans=b[0];
	for(int i=1;i<s;i++){
		ans=ans&b[i];
	}
	cout<<ans;
	return 0; 
}
