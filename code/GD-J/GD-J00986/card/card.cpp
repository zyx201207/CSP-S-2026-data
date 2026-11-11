#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],t[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(is_sorted(a+1,a+n+1)){
		for(int i=1;i<=n;i++){
			int tp=0;
			for(int j=i;j<=n;j++){
				int last=lower_bound(t+1,t+tp+1,a[j])-t;
				tp=last;
				t[tp]=a[j];
			}
			for(int j=1;j<=tp;j++) ans[t[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else{
		for(int i=1;i<=n;i++){
			int tp=0;
			for(int j=i;j<=n;j++){
				int last=tp+1;
				for(int k=1;k<=tp;k++){
					if(t[k]==a[j]){
						last=k;
						break;
					}
				}
				tp=last;
				t[tp]=a[j];
			}
			for(int j=1;j<=tp;j++) ans[t[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
