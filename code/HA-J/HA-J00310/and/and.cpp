#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000086],b[1000086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}sort(a,a+m);
	for(int i=m-1,j=0;i>=0,j<m;i--,j++){
		b[j]=a[i];
	}int s=b[0];
	for(int i=0;i<n;i++){
		s &= b[i];
	}cout<<s;
	return 0;
}
