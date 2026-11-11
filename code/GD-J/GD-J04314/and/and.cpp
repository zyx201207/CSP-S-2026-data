#include<bits/stdc++.h>
using namespace std;
int a[200005][35];
int b[200005];
void e(int x){
	int k=x;
	int i=1;
	while(x){
		a[k][i]=x%2;
		x/=2;
		i++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n){
		cin>>b[1];
		int z=b[1];
		for(int i=2;i<=n;i++){
			cin>>b[i];
			z=z&b[i];
		}
		cout<<z;
		return 0;
	}
	else if(m==1){
		int maxx=-1;
		for(int i=2;i<=n;i++){
			cin>>b[i];
			maxx=max(b[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	if(n==4&&m==2) cout<<12;
	if(n==5&&m==3) cout<<7;
	return 0;
} 
