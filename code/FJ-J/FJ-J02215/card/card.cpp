#include<iostream>
using namespace std;
long long n,m,a[500001],b[500001],t[500001];
bool f[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=t[a[i]],t[a[i]]=i;
	for(int i=1;i<=m;i++) t[i]=0;
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++) f[i]=1;
		for(int i=p;i<=n;i++){
			t[a[i]]++;
			if(b[i]>=p&&f[b[i]]) for(int j=b[i];j<i;j++) t[a[j]]-=f[j],f[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
