#include<bits/stdc++.h>
using namespace std;
int a[100000007];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int x[100007];
		int n,d;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			int v;
			cin>>v;
			x[j]=v;
		}
		int s=x[n-1]-x[0];
		int c=0;
		for(int j=0;j<n-1;j++){
			if(x[j+1]-x[j]!=1){
				c+=(x[j+1]-x[j]);
			}
		}
		s-=c;
		s/=d;
		a[i]=s;
	}
	for(int i=0;i<t;i++){
		cout<<a[i];
		if(i+1<t){
			cout<<endl;
		}
		
	}
	return 0;
}
