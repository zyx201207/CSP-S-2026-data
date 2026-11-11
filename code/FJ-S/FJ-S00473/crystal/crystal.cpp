#include<bits/stdc++.h>
using namespace std;
long long N=1e5+1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[N],b[N],c[N],max=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=b[i]+c[i-1];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(c[j]-c[i]<=m&&j-i+1>max){
				max=j-i+1;
			}
//			cout<<c[j]-c[i]<<" "<<j-i+1<<endl;
		}
	}
	cout<<max;
	return 0;
} 
