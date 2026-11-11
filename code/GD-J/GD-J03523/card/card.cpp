#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
int t[M];
bool b[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		for(int i=k+1;i<=n;i++){
			if(b[a[i]]==true) {
				int d=0;
				for(d=i-1;d>=1;d--){
					if(a[d]==a[i]) break;
				}
				for(int j=d;j<i;j++){
					b[a[j]]=false;
				}
				b[a[i]]=true;
			}
			else b[a[i]]=true;
		}
		for(int i=1;i<=m;i++){
			if(b[i]==true) t[i]++;
			b[i]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0; 
} 
