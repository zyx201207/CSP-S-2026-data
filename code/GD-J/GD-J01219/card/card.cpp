#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],t[300005],g[500005],t2,c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)t[j]=0;
		t2=1;
		for(int j = i;j <= n;j++){
			if(t[a[j]]){
				for(int k = t[a[j]]+1;k < t2;k++)t[g[k]]=0;
				t2=t[a[j]]+1;
			}else{
				t[a[j]]=t2;
				g[t2]=a[j];
				t2++;
			}
		}
		for(int j = 1;j < t2;j++){
			c[g[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
