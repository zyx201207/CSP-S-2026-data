#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=5e5+10;
int a[N];
int b[N],t[N],p[N],ans[N];

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			b[i]=0;	
		}
		for(int i=1;i<=m;i++){
			p[i]=0;
			t[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]>0){
				for(int k=p[a[j]]+1;k<=cnt;k++){
					t[b[k]]--;
					b[k]=0;
					p[b[k]]=0;
				}
			}else{
				b[++cnt]=a[j];
				p[a[j]]=cnt;
				t[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i]>0)ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
