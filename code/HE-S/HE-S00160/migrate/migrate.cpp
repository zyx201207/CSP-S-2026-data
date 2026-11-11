#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int n,d;
int a[N];

int dis,cnt;

inline void Account(int l, int r, int x, int cst){
	if(x==r){
		if(cst==dis) cnt++;
		if(cst<dis) cnt=1,dis=cst;
	}
	for(int i=x+1; i<=r; i++){
		if(a[i]-a[x]>d) break;
		else Account(l,r,i,cst+1);
	}
}

int main(){
	int C,T;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				dis=INT_MAX,cnt=0;
				Account(i,j,i,0);
				if(cnt==2) ans++;
//				cerr<<dis<<" "<<cnt<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
