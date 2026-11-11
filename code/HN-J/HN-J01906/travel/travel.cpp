#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
bool t,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cin >> c1 >> s1 >> c2 >> s2;
	//同一车厢 
	if(c1==c2){
		cout << 1;
		t = 1;
	}
	else
		cout << 0;
	//同一排 
	if(t==0){
		cout << "000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout << 1;
		f = 1;
	}
	else
		cout << 0;
	//过道同一侧 
	if(f==0){
		cout << "00";
		return 0;
	}
	a = s1[2];
	b = s2[2];
	if((a=="A"&&b=="B")||(a=="B"&&b=="A")||(a=="A"&&b=="C")||(a=="C"&&b=="A")||(a=="B"&&b=="C")||(a=="C"&&a=="B")||(a=="D"&&b=="E")||(a=="E"&&b=="D"))
		cout << 1;
	else
		cout << 0;
	//相邻 
	if((a=="A"&&b=="B")||(a=="B"&&b=="A")||(a=="B"&&b=="C")||(a=="C"&&a=="B")||(a=="D"&&b=="E")||(a=="E"&&b=="D"))
		cout << 1;
	else
		cout << 0;
	return 0;
}
/*
车厢 座位号 
【输入样例1】
 02 01A 02 01B
【样例输出1】
 1111
【样例输入2】
 02 01C 02 01A
【样例输出2】
 1110

问题:同一车厢,同一排,过道同一侧,相邻 

 A  B  C  D  E
 
 02 02B 02 01A
*/

/*
Trick||Treat!
*/
