/*
地铁（subway）
怪不得河神不考S，s太……了。。。 
#神了，要爆0了 
*/
#include<bits/stdc++.h>
using namespace std;
long long ans;
long long c,n,m,d,q,x,y;
long long w[5005];
long long a[50005];
long long t[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		long long k,z;
		cin>>k;
		for(int i=1;i<=2*k;i++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+4*t[1];
	} 
	return 0;
}
