#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],b[N],s,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>b[1]){
			s=i;
			b[1]=a[i];
		}
	}
	a[s]=0;
	sum=b[1];
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>b[i]){
				s=j;
				b[i]=a[j];
			}
		}
		a[s]=0;
		sum=sum&b[i];
	}
	cout<<sum;
	return 0;
}
