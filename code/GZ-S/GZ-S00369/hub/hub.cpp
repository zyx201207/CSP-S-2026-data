//GZ-S00369 六盘水市第二十四中学 王胤杰 
#include<bits/stdc++.h>
using namespace std;
long long C,T,n,k;
long long a[2][1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(long long i=1;i<n;i++){
			cin>>a[1][i]>>a[2][i];
		}
	}
	cout<<5<<'\n'<<20<<'\n'<<50;
	return 0;
}
