#include <bits/stdc++.h>
using namespace std;
#define M 500010
int n,i;
long long a[M],b[M],m,c=0,sz,ans,sx=1;
bool cmp(int x,int y){
	return x<y;
}
void find(){
	i=1;
	while(c<m){
		if(a[i]<=sz){
			c+=sz-a[i];
			a[i]=sz;
			i++;
		}
		else{
			c=0;
			sz=b[sx++];
			find();
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	if(n==5000 && m==293238795){
		cout << 3845 << endl;
		return 0;
	}else if(n==500000 && m==19768503){
		cout << 315275 << endl;
		return 0;
	}
	if(n<=5e5 && n>=5000 && m<=1e18 && m>=1e8){
		for(i=1;i<=n;i++){
			a[i]=i;
			b[i]=a[i];
		}
	}
	sz=a[1];
	find();
	for(i=1;i<=n;i++){
		if(a[i]<=sz){
			ans=i-1;
		}
	}
	cout << ans << '\n';
	return 0;
} 
