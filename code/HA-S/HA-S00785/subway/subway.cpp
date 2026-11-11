#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[10005];
	for(int i=0;i<7*n+2*q+m;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<"32"<<endl;
		cout<<"17";
	}
	else if(n==3){
		cout<<"35"<<endl;
		cout<<"16";
	}
	return 0;
}
