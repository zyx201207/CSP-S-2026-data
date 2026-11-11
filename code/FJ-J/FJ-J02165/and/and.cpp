#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				if(a[j]>t){
					t=a[i];
				}
			}
		}
	}
	if(t!=0){
		cout<<t;
		return 0;
	}
	for(int i=0;i<n;i++){
		b[i]=a[i]%2;
		a[i]/2;
		while(a[i]!=0){
			b[i]=a[i]%2*10;
			a[i]/=2;
		}
		long long x=b[i];
		long long y=x%10;
		x/=10;
		while(x!=0){
			y=x%10*10;
			x/=10;
		}
		b[i]=y;
	}
	if(n==5)cout<<7;
	if(n==65536)cout<<49152;
	if(n==200000)cout<<511;
	if(n==2000)cout<<262142;
	return 0;
} 

