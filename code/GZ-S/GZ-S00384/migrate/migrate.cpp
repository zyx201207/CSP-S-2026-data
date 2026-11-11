//GZ-S00384 ¹ùå°Ðù 
#include<bits/stdc++.h>
using namespace std;
vector<long long> x(4000005);
bool pd(int d,int n,int i,int j,int x1,int x2){
	if(x[i]+2*d>x[j]){
		x2=j;j=i;
	}
	int c=0;
	for(int k=x1;k<x2;k++){
		int r=x[x1]+d,l=x[x2]-d;
		if(c>2) continue;
		if(x[k]>=l&& x[k]<=r) c++;
		if(l<=x[x1]){
			if(k-x1!=2) return 0;
			else if(k-x1==2) return 1;
		}
	}
	if(c==2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long c=0;
		for(int i=1;i<n-1;i++){
			int x1=i,x2;
			for(int j=n;j>i+1;j--)
				if(pd(d,n,i,j,x1,x2)) c++;
		}
		cout<<c<<endl;
	}
	return 0;
}
