#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int m[t];
	for(int i=0;i<t;i++){
		m[i]=0;
	}
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int x[n];
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		for(int j=3;j<n;j++){
			if((x[j]-x[j-1]<=d&&x[j-1]-x[j-3]<=d)&&(x[j]-x[j-2]<=d&&x[j-2]-x[j-3]<=d)&&(x[j]-x[j-3]>d))
				m[i]++;
		}
	}
	for(int i=0;i<t;i++){
		cout<<m[i]<<endl;
	}
	return 0;
}
