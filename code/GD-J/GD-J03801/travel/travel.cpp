#include<bits/stdc++.h>
#define int long long
using namespace std;
string rnum,rpos,xnum,xpos;
bool ans1,ans2,ans3,ans4;
bool check2(string a,string b){
	if(!(a[0]==b[0]&&a[1]==b[1]))return 1;
	else return 0;
}
bool check3(string a,string b){
	int t1=a[2]-'A',t2=b[2]-'A';
	if((t1>=0&&t1<=2&&t2>=0&&t2<=2)||(t1>=3&&t1<=4&&t2>=3&&t1<=4))return 1;
	else return 0;
}
bool check34(string a,string b){
	int t1=a[2]-'A',t2=b[2]-'A';
	if(abs(t1-t2)==1&&!(min(t1,t2)==2&&max(t1,t2)==3))return 1;
	else return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>rnum>>rpos>>xnum>>xpos;
	if(rnum!=xnum){
		cout<<"0000\n";
		return 0;
	}
	if(check2(rpos,xpos)){
		cout<<"1000\n";
		return 0;
	}
	if(check3(rpos,xpos)){
		ans3=1;
	}else{
		cout<<"1100\n";
		return 0;
	}
	if(check34(rpos,xpos)){
		cout<<"1111\n";
	}else cout<<"1110\n";
	return 0;
}
