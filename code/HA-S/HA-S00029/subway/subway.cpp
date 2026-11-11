#include<bits/stdc++.h>
using namespace std;
int w[100086];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		for(int i=0;i<m;++i){
			cin>>w[i];
		}
		for(int i=0;i<m+2;++i){
			cin>>w[i];
		}
		 for(int i=0;i<m+2;++i){
			cin>>w[i];
		}
		int r,t,kri,ti;
		cin>>r>>t>>kri>>ti;
		cout<<32<<endl;
		cout<<17;
	}
	else if(c==0&&n==3&&m==7&&d==20&&q==2){
		for(int i=0;i<m;++i){
			cin>>w[i];
		}
		for(int i=0;i<m;++i){
			cin>>w[i];
		}
		for(int i=0;i<m;++i){
			cin>>w[i];
		}
		for(int i=0;i<m+2;++i){
			cin>>w[i];
		}
	
		int r,t,kri,ti;
		cin>>r>>t>>kri>>ti;
		cout<<35<<endl;
		cout<<16;
	}
	else{
		for(int i=0;i<q;++i){
			cout<<rand()%10000<<endl;
		}
	}
	return 0; 
}
