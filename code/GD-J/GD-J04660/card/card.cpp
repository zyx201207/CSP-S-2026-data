#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200005],d[200005],e[200005],f[200005];
int l,r=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b; 
	for(int i=1;i<=b;i++) {
	d[i]=0;
	f[i]=0;
	}
		
	for(int i=1;i<=a;i++) cin>>c[i];
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(d[c[j]]==0) {
			d[c[j]]=j;}
			else for(int x=d[c[j]];x<j;x++) {
			d[x+1]=0;}

		}
		for(int y=1;y<=b;y++){
			if(d[y]!=0) {
			d[y]=0;
			f[y]+=1;
			
			}
		}
	}
	for(int i=1;i<=b;i++){
			cout<<f[i]<<" ";}
return 0;
}

