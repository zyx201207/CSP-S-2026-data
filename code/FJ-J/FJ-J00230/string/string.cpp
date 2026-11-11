#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
long long a[N],g[N];
char c[N];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i]>>c[i];
	int t = 1;
	g[t]+=a[1];
	for(int i = 2;i <= n;i++){
		if(c[i]==c[i-1]) g[t]+=a[i];
		else g[++t]+=a[i];
	}
	int l = 1,r = t;
	while(l<r){
		if(g[l]==g[r]){
			sum+=g[l];
			l++;
			r--;
		}else if(g[l]<g[r]){
			sum+=g[l];
			g[r]-=g[l];
			l++;
		}else{
			sum+=g[r];
			g[l]-=g[r];
			r--;
		}
	}
	cout<<sum;
	return 0; 
}
