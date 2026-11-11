#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[500001],p,b[500001],c[300001];
bool f;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) c[i]=0;
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			f=1;
			t++;
			for(int k=i;k<t;k++){
				if(b[k]==a[j]){
					f=0;
					t=k;
				}
			}
			if(f==1) b[t]=a[j];
		}
		for(int j=1;j<=t;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
