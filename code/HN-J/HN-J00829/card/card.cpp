#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],maxx,m,ans,b[200005],f,B[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		f=0;
		for(int j=i;j<=n;j++){
			f++;
			for(int k=i;k<=j;k++){
				if(b[k]==a[j]){
					memset(b,0,sizeof(b));
					f=1;
				}
			}
			b[f]=a[j];
		}
		for(int j=1;j<=f;j++){
			B[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<B[i]<<" ";
	}
	return 0;
} 
