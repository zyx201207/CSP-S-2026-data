#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans,o,p;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int o,p;
		cin>>o>>p;
		cout<<o/p-1<<endl;
	}
	return 0;
}
