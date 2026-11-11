#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int l1=0, l2=0;
char p1=0, p2=0;
bool a1=0, a2=0, a3=0, a4=0;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	l1 = (s1[0]-'0')*10+(s1[1]-'0');
	l2 = (s2[0]-'0')*10+(s2[1]-'0');
	p1=s1[2];
	p2=s2[2];
	if(p1=='F')p1='E';
	if(p2=='F')p2='E';
	if(c1 == c2) a1=1;
	if(a1&&(l1 == l2)) a2=1;
	if(a1&&a2&&((max(p1, p2) <= 'C') || (min(p1, p2)) >= 'D')) a3=1;
	if(a1&&a2&&a3&&((p1+1==p2)||(p1-1==p2))) a4=1;
	cout << a1 << a2 << a3 << a4;
	return 0;
}
