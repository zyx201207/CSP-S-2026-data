#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int vs[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		vs[i]=1;
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(!vs[j])continue;
			if((a[j]&(1<<i)))sum++;
		}
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1<<i)))vs[j]=0;
			}
			ans=ans+(1<<i);
		}
	}
	cout << ans;
	return 0;
}