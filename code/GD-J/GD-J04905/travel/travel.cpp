#include<bits/stdc++.h>
using namespace std;
bool f=0,s=0,t=0,fo=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char a1=s1[0],a2=s1[1],a3=s1[2];
	char b1=s2[0],b2=s2[1],b3=s2[2];
	if(c1==c2){
		f=1;
		if(a1==b1&&a2==b2){
			s=1;
			int t1=0,t2=0;
			if(a3=='A'||a3=='B'||a3=='C'){
				t1=1;
			}else{
				t1=2;
			}
			if(b3=='A'||b3=='B'||b3=='C'){
				t2=1;
			}else{
				t2=2;
			}
			if(t1==t2){
				t=1;
				int mi=min(int(a3),int(b3)),ma=max(int(a3),int(b3));
				if(mi+1==ma){
					fo=1;
					cout<<f<<s<<t<<fo;
				}else{
					cout<<f<<s<<t<<fo;	
				}
			}else{
				cout<<f<<s<<t<<fo;
			}
		}else{
			cout<<f<<s<<t<<fo;
		}
	}else{
		cout<<f<<s<<t<<fo;
	}
	
	return 0;
}
