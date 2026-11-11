#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0;
int a[200005];
int c[200005];
void _card(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		int b[200005];
		for(int i=k;i<=n;i++){
			int pd=0;
			b[i]=a[i];
			for(int j=k;j<i;j++){
				if(b[j]==a[i]){
					pd=1;
					break;
				}
			}
			if(pd==1){
				for(int j=k;j<i;j++){
					b[j]=-1;
				}
			}
		}
//		for(int j=k;j<=n;j++){
//			cout<<b[j]<<" ";
//		}
		for(int i=1;i<=m;i++){
			for(int j=k;j<=n;j++){
				if(b[j]!=-1&&b[j]==i){
					c[i]++;
				}
			}
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--){
		_card();
	}
	return 0;
}
