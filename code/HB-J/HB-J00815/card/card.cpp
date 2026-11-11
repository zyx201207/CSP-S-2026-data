#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],d[500005],k,s[500005]={0},v[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		memset(d,0,sizeof(d));
		k=1;
		for(int j=i;j<=n;j++){
			if(!v[a[j]]) d[k]=a[j],v[a[j]]=k,k++;
			else{
				for(int l=v[a[j]]+1;l<k;l++)
					v[d[l]]=0,d[l]=0;
				k=v[a[j]]+1;
			}
		}
		for(int j=1;j<k;j++)
			s[d[j]]++;
	}
	for(int i=1;i<=m;i++) 
		cout<<s[i]<<' ';
	return 0;
}
