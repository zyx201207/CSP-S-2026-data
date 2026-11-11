#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[114514],a[514][514],t[514][554],k[514],x[514],y[514];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
		
		
	}long long ss=0;
	for(int i=0;i<q;i++){
	//cout<<q<<endl;
	ss=0;
	for(int j=x[i];j<=y[i];j++){
		
			ss+=t[j][j+1];
			ss+=t[j][j];
			
		}cout<<ss+w[x[i]]+w[y[i]]<<endl;
	}
	return 0;
}
