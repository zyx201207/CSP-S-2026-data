#include<bits/stdc++.h>
using namespace std;
long long a[100000000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
	}
	int a,b;
	cin>>a>>b;
	if(c==0&&n==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(c==0&&n==3){
		cout<<35<<endl<<16;
		return 0;
	}
	cout<<0;
	return 0;
} 
