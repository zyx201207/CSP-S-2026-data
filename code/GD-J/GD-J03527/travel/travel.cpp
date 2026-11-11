#include<bits/stdc++.h>
using namespace std;
int k(char c){
	if(c=='A'||c=='B'||c=='C') return 1;
	else return 2;
}
bool check(string a,string b){
	string ap,bp;
	ap.push_back(a[0]);ap.push_back(a[1]);
	bp.push_back(b[0]);bp.push_back(b[1]);
	if(ap!=bp) return 0;
	char A=a[2],B=b[2];
	if(A>B) swap(A,B);
	if(A=='C'&&B=='D') return 0;
	if(A=='D'&&B=='F') return 1;
	if(A+1!=B) return 0;
	return 1;
}
int main(){
	//freopen("travel4.in","r",stdin);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ap,bp;
	cin>>c1>>s1>>c2>>s2;
	ap.push_back(s1[0]);ap.push_back(s1[1]);
	bp.push_back(s2[0]);bp.push_back(s2[1]);
	bool xiang,pai,ce,ling;
	if(c1==c2) xiang=1;else xiang=0;
	if(ap==bp&&c1==c2) pai=1;else pai=0;
	if(pai==1&&k(s1[2])==k(s2[2])) ce=1;else ce=0;
	if(check(s1,s2)&&c1==c2) ling=1;else ling=0;
	cout<<xiang<<pai<<ce<<ling;
	return 0;
}
