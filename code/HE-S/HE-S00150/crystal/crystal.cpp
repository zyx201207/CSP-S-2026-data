#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n;
	cin>>m;
	cin>>a[m];
	for(int i=0;i<m;i++){
		m= a[i]+a[i+1];
		cout<<3<<endl;
		
	}
	return 0;
}

