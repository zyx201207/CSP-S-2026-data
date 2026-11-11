#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool b[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,czs=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int czm=0;
		for(int j=1;j<=n;j++){
			if(b[j]==0&&(a[j]&(1<<i))){
				czm++;
			}
		}
		if(czm>=m){
			czs+=(1<<i);
			for(int j=1;j<=n;j++){
				if(b[j]==0&&(a[j]&(1<<i))==0){
					b[j]=1;
				}
			}
		}
	}
	cout<<czs;
	return 0;
} 
