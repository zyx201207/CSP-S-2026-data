#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[M],c[N],d[M],ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		memset(d,0,sizeof(d));
		ans=0;
		for(int j=i;j<=n;j++){
			ans++;
			if(d[a[j]]){
				for(int k=d[a[j]]+1;k<ans;k++){
					d[c[k]]=0;
				}
				ans=d[a[j]];
			}else{
				c[ans]=a[j];
				d[a[j]]=ans;
			}
		}
		for(int j=1;j<=ans;j++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << b[i] << " ";
	}
	return 0;
}

