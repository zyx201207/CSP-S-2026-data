#include<bits/stdc++.h>
using namespace std;
long long n,m,z,res;
const int MAXN =100005;
int a[MAXN],b[MAXN];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
}
	sort(a+1,a+n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			z=z+a[i]-a[j];
			}
		b[i]=z;
		}
	for(int i=1;i<=n;i++){
		if(i==n){
			res=n;}
		else if(b[i]>=m&&b[i+1]>m){
			res=i;
			break;
			}
		}
	cout<<res;
	return 0;
		}
