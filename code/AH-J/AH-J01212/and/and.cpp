#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],s=-1,l,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for( int i=0;i<n;i++)
		cin >> a[i];
	while(a[0]>0){
			l=l*10+(a[0]%2);
			a[0]=a[0]/2;
		}
	for( int i=1;i<n;i++){
		int j=0;
		while(a[i]>0){
			j=j*10+(a[i]%2);
			a[i]=a[i]/2;
		}
		y=l&j;
		l=j;	
		s=max(y,s);
	}
	cout<<s;
	return 0;
}
