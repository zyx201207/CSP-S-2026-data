#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char t1=s1[2],t2=s2[2];
	if(c1==c2){
		cout<<1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			cout<<1;
			bool sd1,sd2;
			switch(t1){
				case 'A':sd1=0;break;
				case 'B':sd1=0;break;
				case 'C':sd1=0;break;
				case 'D':sd1=1;break;
				case 'F':sd1=1;break;
			}
			switch(t2){
				case 'A':sd2=0;break;
				case 'B':sd2=0;break;
				case 'C':sd2=0;break;
				case 'D':sd2=1;break;
				case 'F':sd2=1;break;
			}
			if(sd1==sd2){
				cout<<1;
				if(t1<t2) swap(t1,t2);
				if(t1-t2==1&&!(t1=='D'&&t2=='C')) cout<<1<<"\n";
				else cout<<0<<"\n";
			}else cout<<"00\n";
		}else cout<<"000\n";
	}else cout<<"0000\n";

	return 0;
}

