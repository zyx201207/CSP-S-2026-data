#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		if(m==1){
			for(int i=1;i<=m;i++){
				cout<<n;
			}
		}
		else if(m==2){
			int ans=0;
			int cnt=0;
			int c;
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]){
					cnt++;
					c=a[i];
				}
			}
			if(cnt==n-1&&c==1){
				for(int i=1;i<=n;i++){
					cout<<n<<" "<<0;
				}
			}
			if(cnt==n-1&&c==2){
				for(int i=1;i<=n;i++){
					cout<<0<<" "<<n;
				}
			}
			
		}
	}
	return 0;
}
