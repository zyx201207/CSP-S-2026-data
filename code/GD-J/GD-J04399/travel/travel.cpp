#include<bits/stdc++.h>
using namespace std;
const unsigned long long F = 3; 
int a1,b1;
string a2,b2,l = "ABC",r = "FD",s1 = "AB",s2 = "BC",s3 = "FD";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else cout<<0;
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else cout<<0;
	if((a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1])&&(r.find(a2[2])<F&&r.find(b2[2])<F||l.find(a2[2])<F&&l.find(b2[2])<F)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1])&&(r.find(a2[2])<F&&r.find(b2[2])<F||l.find(a2[2])<F&&l.find(b2[2])<F))&&(s1.find(a2[2])<F&&s1.find(b2[2])<F||s2.find(a2[2])<F&&s2.find(b2[2])<F||s3.find(a2[2])<F&&s3.find(b2[2])<F)){
		cout<<1;
	}else cout<<0;
	
	return 0;
}
