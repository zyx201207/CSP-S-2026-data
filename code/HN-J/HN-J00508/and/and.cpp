#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,ans,cnt;
int a[N],b[50],v[N];
void f(int x){
	int t=0;
	while(x>0){
		b[t]+=(x%2);
		x/=2;
		t++;
	}
}
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(v[i]==0&&(a[i]/(1<<x))%2==1)cnt++;
	}
	return cnt>=m;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f(a[i]);
	}
	for(int i=0;i<=30;i++){
		//cout<<i<<' '<<b[i]<<endl;
	}
	for(int k=30;k>=0;k--){
		if(b[k]<m)continue;
		if(!check(k))continue;
		for(int i=1;i<=n;i++){
			if(!(v[i]==0&&(a[i]/(1<<k))%2==1)){
				v[i]=1;
			}
		}
		ans+=(1<<k);
	}
	cout<<ans;
	return 0;
}
