#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a!=b){
		cout<<"0000"<<endl;
		return 0;
	}else{
		cout<<1;
	}
	if(x[0]==y[0]&&x[1]==y[1]){
		cout<<1;
		
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	bool ap=true;
	bool bp=true;
	for(int i=0;i<3;i++){
		if(x[2]==('A'+i)){
			ap=false;
		}
	}
	for(int i=0;i<3;i++){
		if(y[2]==('A'+i)){
			bp=false;
		}
	}
	if(ap==bp){
		cout<<1;
	}else{
		cout<<"00"<<endl;
		return 0;
	}
	if(y[2]+1==x[2]||y[2]-1==x[2]){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
		return 0;
	}
	
	
	return 0;
}

//我常常追忆过去。 
