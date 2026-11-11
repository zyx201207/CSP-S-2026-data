#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,b[300005],c[300005],d[500005],e[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int v=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				e[v]=a[j];
				b[a[j]]++;
				c[a[j]]=v;
				v++;
				
			}else{
				v=c[a[j]]+1;
				e[v]=a[j+1];
			}
		}
		
		v-=1;
		for(int j=i;j<=n;j++){
			b[a[j]]=0;
			c[a[j]]=0;
		}
		for(int j=1;j<=v;j++){
			d[e[j]]++;
			if(e[j]==e[j-1]){
				d[e[j]]--;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<d[j]<<" ";
	}
}

