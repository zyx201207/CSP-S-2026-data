#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    ll x=0,f=1;char ch = getchar();
    while(ch < '0'||ch > '9'){if(ch == '-')f=-1;ch = getchar();}
    while(ch >='0'&&ch <='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 2e5+10;
int a[N];
int n,m;
int vis[N];
ll mx = 0;
void dfs(int x,ll cnt){
	if(x > m){
		mx = max(mx,cnt);
		return;
	}
	for(int i = 1;i <= n;i ++){
		if(!vis[i]){
			vis[i] = 1;
			if(x == 1){
                dfs(x+1,a[i]);
			}else{
                dfs(x+1,cnt&a[i]);
			}
			vis[i] = 0;
		}
	}

}
bool out[1 << 21];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n = read(),m=read();
	int num = 1;
	for(int i = 1;i <= 21;i ++){
		num *=2;
		out[num-1] = 1;
	}
	int flag=0;
	for(int i = 1;i <= n;i ++ ) {
		a[i]= read();
		if(out[a[i]])flag ++;
	}
	if(flag == n){
		sort(a+1,a+n+1);
		int qwq = 1;
		int cnt = a[n];

		for(int i = n-1;i >= 1;i --){
			if(qwq>m){
				cout << cnt;
				return 0;
			}
			cnt=cnt&a[i];
			qwq++;
		}

	}
	dfs(1,0);
	printf("%lld",mx);
	return 0;
}

