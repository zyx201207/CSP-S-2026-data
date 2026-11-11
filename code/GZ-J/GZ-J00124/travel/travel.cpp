// 遵义市第四中学 杨浩辰 GZ-J00124 
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#define f front
#define w back 
using namespace std;
typedef long long ll;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	cout << s1<<s2<<s3<<s4<<endl;
	cout << (s1==s3);
	cout << ((s1==s3)&&(s2[0]==s4[0])&&(s2[1]==s4[1]));
	bool s = ((s1==s3)&&(s2[0]==s4[0])&&(s2[1]==s4[1]));
	if (s==0) {
		cout << "00";
		return 0;
	}
	char c1 = s2[2], c2 = s4[2], c3;
	if (c1 > c2) swap(c1,c2);
	if (c1=='A'&&(c2=='B'))	{
		cout << "11";
	} else if (c1=='A'&&(c2=='C')) {
		cout << "10";
	} else if (c1=='D'&&c2=='F') {
		cout << "11";
	} else {
		cout << "00";
	}
	return 0;
}
