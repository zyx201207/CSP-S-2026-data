#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
typedef long long ll;
int n,m,a[N],c[N],b[N];
bool f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	memset(f,0,sizeof(f));
    	memset(c,0,sizeof(c));
    	for(int j=i;j<=n;j++){
    	    int s=a[j];
    	    if(f[s]){
    	    	for(int k=j-1;k>c[s];k--) f[a[k]]=0;
			}
			f[s]=1,c[s]=j;
		}
		for(int i=1;i<=m;i++){
			if(f[i]) b[i]++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
