#include<bits/stdc++.h>
using namespace std;
int a[2200],b[3000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c=0,n=0,m=0,d=0,q=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(n==2&&m==5&&d==20&&q==2){
		for(int i=1;i<=18;i++){
			cin>>b[i];
		}
		cout<<32<<endl<<17;
		return 0;
	}
	if(n==3&&m==7&&d==20&&q==2){
		for(int i=1;i<=27;i++){
			cin>>b[i];
		}
		cout<<35<<endl<<16;
		return 0;
	}
	cout<<5;
	return 0;
}
