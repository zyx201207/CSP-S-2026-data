#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1,c1,a2,c2,p1,p2,q1,q2;
	cin>>a1>>c1>>a2>>c2;
	for(int i=0;i<=1;i++){
		p1[i]=c1[i];
		p2[i]=c2[i];
	}
	q1[0]=c1[c1.size()-1];
	q2[0]=c2[c2.size()-1];
	if(a1==a2){
		cout<<"1";
		if(p1[0]==p2[0]&&p1[1]==p2[1]){
			cout<<"1";
			if((q1[0]<='C'&&q2[0]<='C')||(q1[0]>='D'&&q2[0]>='D')){
				cout<<"1";
				if(q1[0]+1==q2[0]||q1[0]-1==q2[0]){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
