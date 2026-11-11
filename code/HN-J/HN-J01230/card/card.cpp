#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005];
bool p[500005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[a[j]]==true){
				cout<<a[j]<<endl;
				int y=j;
				while(b[y]!=a[j]){
					b[y]=0;
					p[b[y]]=false;
					y--;
				}
				//b[y]=0;
			}else{
				p[a[j]]=true;
			}
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			c[b[j]]++;
		} 
		for(int j=i;j<=n;j++){
			cout<<b[j]<<" ";
		}
		cout<<endl;
		memset(p,false,sizeof(p));
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" "; 
	}
	return 0;
}
