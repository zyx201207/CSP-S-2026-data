#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],amax=0,mmax=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>=amax){
			mmax=amax;
			amax=a[i];
		}
	}
	cout<<mmax;
	return 0;
}
