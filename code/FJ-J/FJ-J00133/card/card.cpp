#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[90005],d[90005];
int b[90005],c[90005];
void f(int x,int y){
	for(int i=x-1;i>=y;i--){
		if(b[x]==b[i]){
			for(int j=i;j<=x-1;j++){
				b[j]=-1;
			}
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=n-i+1;j>=1;j--){
			b[j]=a[j];
			if(d[b[j]]>1){
				f(j,1);
			}
		}
		for(int j=1;j<=n-i+1;j++){
			c[b[j]]++;
		}
	}
	cout<<n;
	for(int i=2;i<m;i++){
		cout<<" "<<d[i];
	}
	cout<<" "<<m;
	return 0;
}
