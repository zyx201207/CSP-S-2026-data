#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],lst[N],nxt[N],cyb,cf[N],q[N],hhc,ans[N];
bool flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		if(a[i]<a[i-1])
			flag=false;
	}
	if(flag){
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1])
				cout<<i-1<<" ";
		return 0;
	}
	cyb=n+1;
	nxt[n+1]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=cyb;
		if(lst[i]!=i)
			cyb=i;
	}
	for(int i=1;i<=n;i++){
		hhc=i;
		while(hhc<=n){
			if(lst[a[hhc]]==hhc){
				cf[hhc]++;
				cf[nxt[hhc]]--;
				hhc=nxt[hhc];
			}else
				hhc=lst[a[hhc]];
		}
	}
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+cf[i];
		ans[a[i]]+=q[i];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}

