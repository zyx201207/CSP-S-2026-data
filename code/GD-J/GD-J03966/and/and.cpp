#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300000][50],w[300000],q[300000],s1,s,p,x[300000],y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>y;
		while(y){
			a[i][w[i]++]=y%2;
			y/=2;
		}
	}
	s1=pow(2,32);
	for(int i=32;i>=0;i--){
		p=0;
		for(int j=0;j<n;j++){
			if(q[j]==0&&a[j][i]==1){
				x[j]=1;
				p++;
			}
		}
		if(p>=m){
			for(int j=0;j<n;j++){
				if(x[j]!=1)q[j]=1;
				x[j]=0;
			}
			s+=s1;
		}
		s1/=2;
	}
	cout<<s;
	return 0;
}
