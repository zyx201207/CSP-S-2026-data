#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],c[300010],d[500010],n,ans,m,zz=1,q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int y=1;y<=n;y++){
		zz=1;
		for(int i=y;i<=n;i++){
			q=d[i];
			if(b[q]!=0){
				zz=b[q];
				b[q]=0;
			}
			a[zz]=q;
			b[q]=zz;
			zz++;
		}
		for(int j=1;j<=zz-1;j++){
			c[a[j]]++;
			b[j]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

