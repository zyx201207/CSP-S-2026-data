#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,temp=0;
int a[500010],b[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]<=a[i])temp=1;
	}
	if(temp==1){
		for(int i=1;i<=n;i++){
			if(a[i]<a[i+1])cout<<i<<" ";
		}
		cout<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,INF,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]<=INF/2){
				for(int k=1;k<=m;k++){
					if(b[k]>b[a[j]] && b[k]<=j)b[k]=INF;
				}
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(b[j]<=INF/2)c[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
