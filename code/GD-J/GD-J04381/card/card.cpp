#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
const int INF=0x3f3f3f3f;
int n,m,a[N];
int ans[M];
signed main(){
   	freopen("card.in","r",stdin);
   	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int top=0;
		int b[n+1];
		for(int j=i;j<=n;j++){
			top++;
			for(int k=1;k<=top;k++){
				if(a[j]==b[k]){
					top=k;
					break;
				}
			}
			b[top]=a[j];
		}
		for(int j=1;j<=top;j++){
//			cout<<b[j]<<" ";
			ans[b[j]]++;
		}
	}
//	cout<<endl;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

