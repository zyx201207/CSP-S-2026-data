#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],c[500005];
struct node{
	int sum,pre;
}b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;++j){
			if(b[a[j]].sum==0){
				b[a[j]].sum=1;
				b[a[j]].pre=j;
			}else{
				for(int k=b[a[j]].pre+1;k<j;++k){
					b[a[k]].sum=0;
				}
				b[a[j]].pre=j;
			}
		}
		for(int j=1;j<=m;++j){
			c[j]+=b[j].sum;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<c[i]<<" ";
	}
	return 0;
}

