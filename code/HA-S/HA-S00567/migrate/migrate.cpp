#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,p;
int a[2000006];
int b[2000006];
void dg(int l,int r,int m){
//	cout<<l<<" "<<r<<" "<<f<<"\n"; 
	if(l==r){
		if(m==p){
			b[r]++;
		}else if(m<p){
			b[r]=1;
			p=m;
		}
		return;
	}
	if(l>r) return;
	int k=l+1;
	while(a[k]-a[l]<=d&&k<=n){
		dg(k,r,m+1);
		k++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int f=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				p=1e9;
				dg(i,j,0);
				if(b[j]>1) f++;
				b[j]=0;
			}
		}
		cout<<f<<"\n";
	}
	return 0;
}
