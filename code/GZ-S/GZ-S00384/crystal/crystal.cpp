//GZ-S00384 ¹ùå°Ðù 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=a[2]-a[1];
	int c=1;
	for(int i=1;i<n;i++){
		m-=i*k;
		if(m<0){
			cout<<c;
			return 0;
		}
		c++;
	}
	int m1=m%n;
	cout<<max(m1,n-m1);
	return 0;
}
