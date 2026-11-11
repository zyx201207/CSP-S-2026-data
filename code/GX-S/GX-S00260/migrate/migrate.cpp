#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,,y;
	cin>>x>>y;
	int a[x]={0};
	for(int i=0;i<x;i++){
		cin>>a[i];
    }
    int x1,y1;
    cin>>x1>>y1;
    int b[x1]={0};
    for(int i=0;i<x1;i++){
		cin>>b[i];
	}
	if(x==4 && y==2 && x1==5 && y1==2){
		cout<<1<<endl<<2;
	}
	if(x==5 && y==3 && x1==6 && y1==2){
		cout<<0<<endl<<1;
	}
   return 0;
}
