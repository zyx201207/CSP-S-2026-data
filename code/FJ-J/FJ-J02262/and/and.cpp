#include<bits/stdc++.h>
using namespace std;
long long a[205][205],z[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,s,sum=0,l,x=1,h=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	sort(z+1,z+n+1);
	for(int i=1;i<=n;i++){
		s=1;
		while(z[i]!=0){
			a[i][s]=z[i]%2;
			z[i]/=2;
			s++;
		}
		if(i==n-m+1){
			l=s;
		}
	}
	for(int i=1;i<l;i++){
		int ok=1;
		x=n;
		while(x>=n-m+1){
			if(a[x][i]==0||a[x-1][i]==0&&x-1>=n-m+1){
				ok=0;
				break;
			}
			x--;
		}
		if(ok){
			sum+=pow(2,i-1);
		}
	}
	cout<<sum;
	return 0;
}
