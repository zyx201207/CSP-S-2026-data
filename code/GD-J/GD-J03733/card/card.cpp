#include<bits/stdc++.h>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
typedef long long ll;
const int N=500010;
int n,m,a[N];
int st[N],tp;
bool instk[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int s=1;s<=n;s++){
		for(int i=s;i<=n;i++){
			while(instk[a[i]]){
				instk[st[tp]]=0;
				tp--;
			}
			instk[a[i]]=1;
			st[++tp]=a[i];
		}
		while(tp){
			ans[st[tp]]++;
			instk[st[tp]]=0;
			tp--;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
