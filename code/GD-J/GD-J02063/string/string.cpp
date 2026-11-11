#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,ans=0;
int d[N],zz=0;
int q[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;zz=n;
	for(int i=1;i<=n;i++){
		char a;cin>>d[i]>>a;
		q[i]=a-'a';
	}for(int i=1;i<zz;){
		if(q[i]==q[zz]){
			int j=min(d[i],d[zz]);
			d[i]-=j;
			d[zz]-=j;
			if(!d[i]){
				i++;
			}else{
				--zz;
			}
		}else{
			int j=min(d[i],d[zz]);
			d[i]-=j;
			d[zz]-=j;
			ans+=j;
			if(!d[i]){
				i++;
			}else{
				--zz;
			}
		}
	}cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
