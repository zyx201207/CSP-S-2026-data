#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
ll ss1,ss2;
ll q1(){
	if(c1==c2) return 1;
	return 0;
}
ll q2(){
	if(q1()==1 and s1[0]==s2[0] and s1[1]==s2[1]) return 1;
	return 0;
}
ll q3(){
	if(q2()==1 and ((s1[2]<='C' and s2[2]<='C') or (s1[2]>='D' and s2[2]>='D'))) return 1;
	return 0;
}
ll q4(){
	if(q3()==1 and (abs(s1[2]-s2[2])==1 or (s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s2[2]=='D'))) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<q1()<<q2()<<q3()<<q4();
	fclose(stdin);
	fclose(stdout);
    return 0;
}
