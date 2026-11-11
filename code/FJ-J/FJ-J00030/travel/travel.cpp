//100 pts
#include<bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
//看数据范围决定 long long , 记得备份文件(得部分分文件)
const int N=4;
int main(){
	ios::sync_with_stdio(false);//Debug(调试)要关闭
	cin.tie(nullptr);cout.tie(nullptr);
	file("travel");//不要注释 freopen,记得检查 freopen 文件名 
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<endl; 
	}else if(!(b[0]==d[0]&&b[1]==d[1])){
		cout<<"1000"<<endl;
	}else if(abs(b[2]-d[2])==1&&!(b[2]=='C'&&d[2]=='D')&&!(b[2]=='D'&&d[2]=='C')){
		cout<<"1111"<<endl;
	}else{
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				cout<<"1110"<<endl;
			}else{
				cout<<"1100"<<endl;
			}
		}else{
			if(d[2]=='D'||d[2]=='F'){
				cout<<"1110"<<endl;
			}else{
				cout<<"1100"<<endl;
			}
		}
	}
	return 0;
}


