#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000006],desk[1000006],b[1000006],c[1000006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool ok=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])ok=false;
	}
	if(ok){
		cout<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				cnt++;
				desk[cnt]=a[j];
				c[a[j]]=cnt;
			}
			else{
				int f=-1;
				for(int k=c[a[j]];k<=cnt;k++){
					c[desk[k]]=0;
					desk[k]=0;
					f++;
				}
				cnt-=f;
				desk[cnt]=a[j];
				c[a[j]]=cnt;
			}
		}
		for(int j=1;j<=cnt;j++){
			b[desk[j]]++;
		}
		memset(desk,0,sizeof(desk));
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
