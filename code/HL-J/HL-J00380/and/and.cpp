#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[200010];
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cnt=pow(2,31)-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=n-m;i--){
		cnt=cnt&a[i];
	}
	cout<<cnt;
	return 0;
} 

