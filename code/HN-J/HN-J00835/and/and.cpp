#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long zd=-1;
	for(int i=1;i<=n;i++){
		long long cnt=a[i];
		for(int j=i;j<=m;j++){
			cnt&=a[j];
		}
		cout<<cnt<<endl;
		if(zd<cnt){
			zd=cnt;
		}
	}
	cout<<zd;
	return 0;
}
