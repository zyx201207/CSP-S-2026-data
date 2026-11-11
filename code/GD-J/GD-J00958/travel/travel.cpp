#include<bits/stdc++.h>
using namespace std;
int calc(char c){
	if(c<='C')return 0;
	return 1;
}
bool check(char s,char t){
	if((s=='A'&&t=='C')||(s=='C'&&t=='A'))
		return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool ans1=(c1==c2);
	bool ans2=(ans1&&(s1[0]==s2[0])&&(s1[1]==s2[1]));
	bool ans3=(ans2&&(calc(s1[2])==calc(s2[2])));
	bool ans4=(ans3&&check(s1[2],s2[2]));
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
//02 01A 02 01B ->1111
//02 01C 02 01A ->1110
//02 01C 02 01D ->1100
//02 02B 02 01A ->1000
//02 01A 03 01A ->0000
/*
this is the competition history
it's valuable and useful,thx!
8:30-8:45 mkdirs,see problems
T1:travel easy!
T2:string how to solve? calm down and think
5e5 times random: without15.56s; closeI/O:2.44s !remember to write ios::...!
9:13-9:23 T1 succeeded.
9:30-10:15 t2 AC(to be quick!!)
10:40-10:50 have a rest and had an idea on T3
this is might be a 2-digit problem and it can be O(30n)
done!!!successful!!!now have 300pts and it's 11:13
still writing T4 guess that I can win!
this is the solution of T4:from back to check everyon that's O(n)
zchzchzch keep it going!!!
*/
