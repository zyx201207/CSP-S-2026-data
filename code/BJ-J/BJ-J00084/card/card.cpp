#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[200005],ans[300005],h[300005],b[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	for(int t=1;t<=n;t++){
		memset(h,0,sizeof h);
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int i=t;i<=n;i++){
			h[a[i]]++;
			for(int j=i-1;j>=t;j--){
				if(b[j]==b[i]){
					for(int k=j;k<i;k++){
						if(b[k]!=-1) h[a[k]]--;
						b[k]=-1;
					}
					break;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(h[i]>0){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
    return 0;
}
