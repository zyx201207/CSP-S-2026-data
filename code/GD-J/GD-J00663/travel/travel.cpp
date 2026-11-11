#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
ll t1=0,t2=0,n1=0,n2=0,k1,k2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		t1=t1*10+c1[i]-'0';
		t2=t2*10+c2[i]-'0';
		n1=n1*10+s1[i]-'0';
		n2=n2*10+s2[i]-'0';
	}
	k1=s1[2]-'A'+1;
	k2=s2[2]-'A'+1;
	if(t1==t2){
		cout<<"1";
		if(n1==n2){
			cout<<"1";
			if(k1<=3&&k1>=1&&k2<=3&&k2>=1){
				cout<<"1";
				if(abs(k1-k2)==1)cout<<"1"<<endl;
				else cout<<"0"<<endl;
			}else if(k1<=5&&k1>=4&&k2<=5&&k2>=4){
				cout<<"11"<<endl; 
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000"<<endl;
		}
	}else {
		cout<<"0000"<<endl;
	}
	return 0;
}

