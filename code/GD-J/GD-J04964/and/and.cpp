#include<bits/stdc++.h>
using namespace std;
int x,n,m,j=31,mx=0,mx1,nw[35],nwb,num;
struct one{
	int a[35],b,r=0;
}c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		mx=max(mx,x);
		while(x){
			c[i].a[j]=x%2;
			x/=2;
			j--;
			c[i].b++;
		}
		j=32;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	for(int y=32;y>=32-c[1].b;y--){
			nw[y]==c[1].a[y];
		}
	for(int g=1;g<=n;g++){
		for(int y=32;y>=32-c[g].b;y--){
			nw[y]==(c[g].a[y]==1&&nw[y]==1);
			if(c[g].a[y]==nw[y]&&nw[y]==1){
				nwb=33-y;
			}
		}
    }
    for(int i=32;i>nwb;i--){
    	num+=nw[i]*2^(32-i);
	}
	cout<<num;
	return 0;
} 
