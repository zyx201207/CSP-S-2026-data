#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
long long n,m,a[N],t[N],x,tt[N],bd=1;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld ",&a[i]);
		if(a[i]<a[i-1])bd=0;
	}
	if(bd){
		cout<<m;
		return;
	}
	for(int i=1;i<=n;i++){
		vector<int> x;
		for(int j=i;j<=n;j++){
			if(tt[a[j]]){
				for(int i=x.size()-1;x[i]!=a[j];i--){
					tt[x[i]]=0;
					x.pop_back();
				}
			}else{
			tt[a[j]]++;
			x.push_back(a[j]);	
			}
		}
		for(int i=1;i<=m;i++)tt[i]=0;
		for(int i:x)t[i]++;
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
} 
