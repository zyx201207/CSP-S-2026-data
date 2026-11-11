#include<bits/stdc++.h>

using namespace std;

const int N=2e6+10;

int c,n,m;
int a[N];
int f[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}f[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=i;j>=1;j--){
				if(abs(a[i]-a[j])<=m){
					f[i]+=f[j];
					continue;
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(f[i]>=2){
				res++;
			}
		}
		cout<<res/2<<endl;
	}
	
	
	return 0;
}
