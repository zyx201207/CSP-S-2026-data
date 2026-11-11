#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string c1 ,s1 ,c2 ,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool ans1=0 ,ans2=0 ,ans3=0 ,ans4=0;
	if(c1==c2) ans1=1;
	if(ans1==1&&s1[0]==s2[0]&&s1[1]==s2[1]) ans2=1;
	if(ans2==1&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) ans3=1;
	if(ans3==1){
		int a=s1[2]-'A' ,b=s2[2]-'A';
		if(abs(a-b)==1) ans4=1;
	}
	cout << ans1 << ans2 << ans3 << ans4 << '\n';
	return 0;
} 
