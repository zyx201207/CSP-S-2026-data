#include<bits/stdc++.h>
using namespace std;
int n,m,h[1005],l=0,k;
int a[1005],b[1005],s[1005];
void q(int o,int u){
	for(int i=o;i<=u;i++){
		a[s[i]]=0;
		s[i]=0;
	}
	return;
}
void r(){
	for(int i=1;i<=l;i++){
		b[s[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int j=1;j<=n;j++){
		for(int y=j;y<=n;y++){
			k=h[y];
			if(!a[k]){
				a[k]=1;
				l++;
				s[l]=k;
			}
			else{
				for(int i=1;i<=l;i++){
					if(k==s[i]){
						q(i+1,l);
						a[k]=1;
						l=i;
					}
				}
			}
		}
		r();
		q(1,l);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
