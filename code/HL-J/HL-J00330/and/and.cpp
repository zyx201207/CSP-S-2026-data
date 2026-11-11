#include<bits/stdc++.h>
using namespace std;
int  a[10000000],b[10000000],maxn;
bool pd[10000000];
int n,m;
void dps(int step){
	if(step>m){
		int it=a[b[1]];
		for(int i=2;i<=m;i++){
			it&=a[b[i]];
		}
		if(it>maxn) maxn=it;
		return;
	}
	for(int i=1;i<=n;i++){
		if(pd[i]==false){
			b[step]=i;
			pd[i]=true;
			dps(step+1);
			pd[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dps(1);
	cout<<maxn;
	return 0;
}