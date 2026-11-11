#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
long long n,nn,m,a[maxn],ans[maxm],b[maxm],Max,ta[maxn],ya[maxn];
bool y;
stack<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])ta[++nn]=a[i];
		ya[nn]++;
		if(Max>a[i])y=true;
		Max=max(Max,a[i]);
	}
	if(!y){
		for(int i=n;i>=1;i--)ans[a[i]]=max(ans[a[i]],(long long)i);
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	n=nn;
	for(int i=1;i<=n;i++)a[i]=ta[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==i){
				while(q.top()!=a[j]){
					b[q.top()]=0;
					q.pop();
				}
				q.pop();
			}
			q.push(a[j]);
			b[a[j]]=i;
		}
		while(!q.empty()){
			ans[q.top()]+=ya[i];
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
