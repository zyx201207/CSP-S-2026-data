#include<bits/stdc++.h>
using namespace std;
int n,m,x,l,r;
int a[200005],t[200005],ans;
bool b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=0;
	for(int i=n+1;i<=4*n;i++){
		a[i]=a[i-n*p];
		if(i%n==0) p++;
	}
	for(int i=1;i<=4*n;i++){
		for(int j=1;j<i;j++){
			if(i!=j&&a[i]==a[j]&&b[j]==0){
				l=j;r=i-1;
				break;
			}
		}
		for(int j=l;j<=r;j++) b[j]=1;
		l=0;r=0;
		if(i%n==0){
			x++;
			for(int j=1;j<=n*x;j++){
				if(b[j]==0) t[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
return 0;
}
