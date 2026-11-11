#include<bits/stdc++.h>
using namespace std;
long long n,p;
long long a[200005],m[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	m[1]=a[1];
	for(long long i=2;i<=n;i++){
		for(int j=min(i,p);j>=1;j--){
			m[j]=max(m[j],m[j-1]&a[i]);
//			cout<<i<<" "<<j<<" "<<m[j]<<endl;
		}
		m[1]=max(m[1],a[i]);
	}
	long long maxx=0;
//	for(int i=1;i<=p;i++) cout<<m[i]<<endl;
	cout<<m[p];
	return 0;
}

