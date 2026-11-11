#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7,J=31;
int n,m,a[N],res;
bool p[N],q[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(p,1,sizeof(p));
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int b=J-1;b>=0;b--){
		memset(q,0,sizeof(q));
		int s=0;
		for(int i=0;i<n;i++)
			if(p[i]&&(a[i]>>b&1))
				q[i]=1,s++;
		if(s>=m){
			memcpy(p,q,sizeof(p));
			res|=(1<<b);
		}
	}
	cout<<res<<endl;
	return 0;
}
