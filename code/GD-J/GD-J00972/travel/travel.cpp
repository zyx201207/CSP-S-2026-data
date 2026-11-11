#include<bits/stdc++.h>
using namespace std;
string a,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>aa>>bb;
	if(a==aa) cout<<1;//同车箱 
	else{
		cout<<"0000";
		return 0;
	}
	bool c=1;
	for(int i=0;i<=1;i++){
		if(b[i]!=bb[i]){
			c=0;
		}
	}
	if(c==0){//不同排 
		cout<<"000";
		return 0;
	}else{//同排 
		cout<<1;
		if(((b[2]=='A' || b[2]=='B' || b[2]=='C') && (bb[2]=='A' || bb[2]=='B' || bb[2]=='C'))){//同左侧过道 
			cout<<1;
			if((b[2]=='A' && bb[2]=='B') || (bb[2]=='A' && b[2]=='B') || (b[2]=='C' && bb[2]=='B') || (bb[2]=='C' && b[2]=='B')){//左邻座 
				cout<<1;
				return 0;
			}else{
				cout<<"0";
			}
		}else if((b[2]=='C' || b[2]=='D') && (bb[2]=='C' && bb[2]=='D')){//过道相邻 
			cout<<"00";
			return 0;
		}else if(((b[2]=='D' || b[2]=='F') && (bb[2]=='D' || bb[2]=='F'))){//同右侧过道 
			cout<<11;
			return 0;
		}
		cout<<"00";
	}
	return 0;
}

