#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[300010],cnt1[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=true;
	}
	if(f==true){
		for(int i=1;i<=n;i++){
			memset(c,0,sizeof(c));
			for(int j=i;j<=n;j++){
				b[j]=a[j];
				if(c[a[j]]==0) c[a[j]]=j;
			}
			int cnt=n;
			for(int j=i;j<=n;j++){
				if(c[a[j]]==0) b[++cnt]=a[j],c[a[j]]=cnt;
				else{
					cnt=c[a[j]];
					for(int k=c[a[j]]+1;k<=n;k++){
						if(c[b[k]]==k) c[b[k]]=0;
					}
				}
			}
			for(int j=i;j<=cnt;j++){
				cnt1[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<cnt1[i]<<" ";
	}
	else{
		for(int i=1;i<=n;i++) c[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	}
	return 0;
}
/*
1 2 1 3
1
1 2
*/
