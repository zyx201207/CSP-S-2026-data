#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map <int,int> b;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans[500005];
	for(int i=1;i<=n;i++){
		int now=0,apt=0;
	    for(int j=i;j<=n;j++){
			now++;
			b[now]=a[j];
			for(int k=i;k<=j;k++){
				if(b[k]==b[j]&&k!=j) {
					apt=k;
					break;
				}
			}
			if(apt!=0){
				for(int k=apt;k<j;k++){
			    b[k]=0;
			}
			apt=0;
		}
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0){
				ans[b[j]]++;
			}
		}
		b.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}