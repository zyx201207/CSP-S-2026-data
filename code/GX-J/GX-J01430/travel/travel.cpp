#include<bits/stdc++.h>
using namespace std;
bool b1,b2,b3,b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){//tong yi ge che xiang
		b1=1;
		string xh=b.substr(0,2);
		string yh=d.substr(0,2);
		string xl=b.substr(2,1);
		string yl=d.substr(2,1);

		if(xh==yh){//tong yi pai(hang)
			b2=1;
			if(xl=="A"&&yl=="B"){//tong yi ce &xiang ling
				b3=1;
				b4=1;
			}
			else if(xl=="A"&&yl=="C"){
				b3=1;
				b4=0;
			}
			else if(xl=="A"&&yl=="D"){
				b3=0;
				b4=0;
			}
			else if(xl=="A"&&yl=="F"){
				b3=0;
				b4=0;
			}
			else if(xl=="B"&&yl=="A"){
				b3=1;
				b4=1;
			}
			else if(xl=="B"&&yl=="C"){
				b3=1;
				b4=1;
			}
			else if(xl=="B"&&yl=="D"){
				b3=0;
				b4=0;
			}
			else if(xl=="B"&&yl=="F"){
				b3=0;
				b4=0;
			}
			else if(xl=="C"&&yl=="A"){
				b3=1;
				b4=0;
			}
			else if(xl=="C"&&yl=="B"){
				b3=1;
				b4=1;
			}
			else if(xl=="C"&&yl=="D"){
				b3=0;
				b4=0;
			}
			else if(xl=="C"&&yl=="F"){
				b3=0;
				b4=0;
			}
			else if(xl=="D"&&yl=="A"){
				b3=0;
				b4=0;
			}
			else if(xl=="D"&&yl=="B"){
				b3=0;
				b4=0;
			}
			else if(xl=="D"&&yl=="C"){
				b3=0;
				b4=0;
			}
			else if(xl=="D"&&yl=="F"){
				b3=1;
				b4=1;
			}
			else if(xl=="F"&&yl=="A"){
				b3=0;
				b4=0;
			}
			else if(xl=="F"&&yl=="B"){
				b3=0;
				b4=0;
			}
			else if(xl=="F"&&yl=="C"){
				b3=0;
				b4=0;
			}
			else if(xl=="F"&&yl=="D"){
				b3=1;
				b4=1;
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
