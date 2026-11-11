#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m;
int a[N],t[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(t,0,sizeof(t));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		if(t[a[i]]==0)
			t[a[i]]=i;
	for(int i=1;i<=n;i++){
		int p=i;
		while(true){
			int k=t[a[p]];
			if(k==p){
				while(p<=n&&p==t[a[p]]){
					ans[a[p]]++;
					p++;
				}
			}else{
				p=k;
				ans[a[p]]++;
				p++;
			}
			if(p>n)break;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
