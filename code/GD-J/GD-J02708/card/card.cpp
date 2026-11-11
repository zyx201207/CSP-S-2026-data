#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int l,r;
};
stack<int>S;
int n,m,a[N],la[N],wz[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		la[i]=wz[a[i]];
		wz[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++)wz[i]=0;
		for(int j=i;j<=n;j++){
			if(wz[a[j]]){
				while(S.top()!=a[j]){
					wz[S.top()]=0;
					S.pop();
				}
				S.pop();
			}
			S.push(a[j]);
			wz[a[j]]=1;
		}
		while(S.size())S.pop();
		for(int i=1;i<=m;i++)ans[i]+=wz[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
