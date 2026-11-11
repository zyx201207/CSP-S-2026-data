#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	int ans1=(c1==c2),ans2=(s1[0]==s2[0]&&s1[1]==s2[1]),ans3=0;
	cout << ans1;
	cout << (ans1&&ans2);
	int p1=s1[2]-'A'+1,p2=s2[2]-'A'+1;
	if(p1==6) p1--;
	if(p2==6) p2--;
	if(p2<p1) swap(p1,p2);
	if(p2<=3){cout << (ans1&&ans2);ans3=1;}
	else if(p1>=4) {cout << (ans1&&ans2);ans3=1;}
	else {cout << 0;ans3=0;}
	if(!(ans1&&ans2&&ans3)) cout << 0;
	else {
		if(p2-p1==1) cout << 1;
		else cout << 0;
	}
	return 0;
}
