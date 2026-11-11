#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt=0,b[500010],c[500010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cnt=0;
		for(int j=i-1;j<=n;j++){
			cnt++;
			int wz;
			bool f=true;
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]) f=false,wz=k;
			}
			if(f) b[cnt]=a[j];
			else{
				for(int k=wz;k<=n;k++) b[k]=0;
				b[cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			if(b[j]!=0) c[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	 return 0;
}
