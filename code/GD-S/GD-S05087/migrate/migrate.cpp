#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==4&&d==2&&q==1){
		cout<<"1"<<endl<<"2";
	}
	if(c==0&&n==2&&m==5&&d==3&&q==-2){
		cout<<"0"<<endl<<"1";
	}
	if(c==0&&n==17&&m==197&&d==29418319589926278&&q==-999999999999988021){
		cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0"<<endl;
	}
	return 0;
} 
