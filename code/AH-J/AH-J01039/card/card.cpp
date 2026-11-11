#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],b[N],c[N],ans[N];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]=i;
		if(f&&a[i]<a[i-1]) f=0;
	}
	if(f){
		for(int i=1;i<=k;i++)
			cout<<c[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int p=j-1;a[p]!=a[j];p--)
					b[a[p]]=0;
			}
			b[a[j]]=1;
		}
		for(int j=1;j<=k;j++)
			if(b[j]) ans[j]++;
	}
	for(int i=1;i<=k;i++)
		cout<<ans[i]<<' ';
	return 0;
}
