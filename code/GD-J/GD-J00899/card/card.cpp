#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
const int M=3e5+9;
int a[N],l[M],ans[M];
int n,m;
void read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
}
void solve1(){
	int x=(a[n]+1)%2;
	for(int i=1;i<=n;i++){
		if(a[i]==x) ans[x]++;
	}
	ans[a[n]]=n;
	cout<<ans[1]<<" "<<ans[2]<<endl;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	if(m==2) solve1();
	return 0;
}
