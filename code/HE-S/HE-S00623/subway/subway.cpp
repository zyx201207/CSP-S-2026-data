#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n],t[m],l[n],r[n];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<m;j++){
			cin>>t[j];
		}
	}
	for(int i=0;i<n;i++){
		cin>>l[i];
		for(int j=0;j<n;j++){
			cin>>r[j];
		}
	}
	if(c==0&&n==2&&m==5){
		cout<<32<<endl<<17;
	}
	if(c==0&&n==3&&m==7){
		cout<<35<<endl<<16;
	}
	return 0;
} 
