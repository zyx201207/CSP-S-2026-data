#include<bits/stdc++.h>
using namespace std;
long long n,max1=-1,a[200200],x;
char b[200200];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>max1)max1=a[i];
	}
	cout<<max1;
	return 0;
}
