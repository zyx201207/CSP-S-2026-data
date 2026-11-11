#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	int t; cin>>t;
	string cl,sl,cr,sr;
	cin>>cl>>sl>>cr>>sr;
	if(cl==cr)
	{
		cout<<1;//同车厢 
	}
	 
	else  
	{
		cout<<"0000";//不同车厢
		return 0; 
	}
	int cnt=0;
	for(int i=0;i<2;i++){//同一排 
		if(sl[i]==sr[i]){
			cnt++;
		}
	}
	if(cnt==2){//同一排 
		cout<<1;
		bool tc=false;
		if(sl[2]=='A' || sl[2]=='B' || sl[2]=='C'){//同一侧 
			if(sr[2]=='A' || sr[2]=='B' || sr[2]=='C'){
				cout<<"1";
				tc==true;
				if((sl[2]+1) == sr[2] || (sl[2]-1) == sr[2]) {//相邻 
					cout<<"1";
					return 0;
				}else{
					cout<<"0"; 
					return 0;
				}
			}
		}
		else if(sl[2]=='D' || sl[2]=='F'){
			if(sr[2]=='D' || sr[2]=='F'){
				tc==true;
				cout<<"1";
				if(sl[2]!=sr[2])
				{
					cout<<"1";
					return 0;
				 } 
				else {
					cout<<"0";
					return 0;
				}
			}
		}
		if(!tc){
			cout<<"00";
			return 0; 
		}
	}else{
		cout<<"000";
	}
	return 0;
} 
