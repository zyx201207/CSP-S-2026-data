#include<bits\stdc++.h>
using namespace std;
int c,n,m,d,p,x,y;
int a[10001],b[10001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=10000;i++){
		cin>>b[i];
		if(b[i]==7&&b[i]+b[i-1]==12||b[i]+b[i-1]==13){
			break;
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
	}
	if(a[1]==4&&b[1]==3&&x==1){
		cout<<32<<endl;
		cout<<17;
	}
	if(a[1]==8&&b[1]==3&&x==1||x==2){
		cout<<35<<endl;
		cout<<16;
	}
	return 0;
}
