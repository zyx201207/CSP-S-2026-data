#include<iostream>
#include<cstring>
using namespace std;
int x1,z1,x2,z2;
char w1,w2;
string c1,s1,c2,s2;
bool left(char ch) {
	return ch=='A'||ch=='B'||ch=='C';
}
bool near(char ch1, char ch2) {
	if (ch1>ch2)
		swap(ch1,ch2);
	if (ch2-ch1==1)
		return true;
	if (ch2=='F' && ch1=='D')
		return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>c1>>s1>>c2>>s2;
	x1=stoi(c1);
	z1=stoi(s1);
	w1=s1[s1.size()-1];
	x2=stoi(c2);
	z2=stoi(s2);
	w2=s2[s2.size()-1];
	
	cout<<(x1==x2 ? 1 : 0);
	cout<<(x1==x2 && z1==z2 ? 1 : 0);
	cout<<(x1==x2 && z1==z2 && left(w1)==left(w2) ? 1 : 0);
	cout<<(x1==x2 && z1==z2 && left(w1)==left(w2) && near(w1,w2) ? 1 : 0);
	return 0;
} 
