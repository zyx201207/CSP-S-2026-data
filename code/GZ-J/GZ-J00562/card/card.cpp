//GZ-J00562，戚星汉，贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int a[N],n,m,b[M],ans[M],k,g[N],l[N],p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		k=1; 
		for(int j=i;j<=n;j++){
			g[k]=a[j];
			if(b[g[k]]){
				k=b[g[k]];
			}
			else{
				b[g[k]]=k;
			}
			k++;
		}
		memset(b,0,sizeof(b));
		p=1; 
		for(int j=1;j<k;j++){
			l[p]=g[j];
			if(b[l[p]]){
				p=b[l[p]];
			}
			else{
				b[l[p]]=p;
			}
			p++;
		}
		for(int j=1;j<p;j++){
			ans[l[j]]++;
	 	}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
