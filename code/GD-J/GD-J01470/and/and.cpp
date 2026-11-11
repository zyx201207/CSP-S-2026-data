#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],e[200010][101],zgw,s=2147483647;
bool bl[200010];
void ejz(int x,int gs){
	int l=1;
	while(x>0){
		l++;
		e[gs][l]=x%2;
		x/=2;
	}
	e[gs][1]=l;
	zgw=max(zgw,l);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ejz(a[i],i);
	}
	for(int i=zgw;i>=2;i--){
		int ysl=0;
		for(int j=1;j<=n;j++){
			if(!bl[j])ysl+=e[j][i];
		}
		if(ysl>=m){
			for(int j=1;j<=n;j++){
				if(!e[j][i])bl[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!bl[i])s&=a[i];
	}
	cout<<s;
}
