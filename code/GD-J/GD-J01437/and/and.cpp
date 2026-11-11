#include<bits/stdc++.h>
using namespace std;
const int ma=200005;
int a[ma],b[ma];
int c[ma][100];
int f;
int d[ma],t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>b[i]){
				f=j;
				b[i]=a[j];
			}
		}
		a[f]=0;
	}
	int f2=0;
	for(int i=1;i<=m;i++){
		int f1=1;
		while(b[i]!=0){
			c[i][f1]=b[i]%2;
			f1++;
			b[i]=b[i]/2;
		}
		f2=max(f2,f1-1);
	}
	for(int i=1;i<=f2;i++){
		int tf=c[2][i]&c[1][i];
		for(int j=3;j<=m;j++){
			tf=tf&c[j][i];
		}
		d[i]=tf;
	}
	for(int i=1;i<=f2;i++){
		t+=d[i]*pow(2,i-1);
	}
	cout<<t;
	
	return 0;
} 
