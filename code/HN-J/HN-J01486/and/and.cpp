#include<bits/stdc++.h>
using namespace std;
long long n,m,b[1000000],a[1000000],a1=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
		for(int j=i+1;j<n;j++){
			a[a1++]=b[i]&b[j];
		}
	}
	sort(a,a+a1);
	cout<<a[a1-1];
	return 0;
}
