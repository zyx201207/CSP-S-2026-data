#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cr[300];
	cr[int('A')]=1;
	cr[int('B')]=1;
	cr[int('C')]=1;
	cr[int('D')]=2;
	cr[int('F')]=2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2) { //同一个车厢
		cout<<1;
		if (s1[0]==s2[0] && s1[1]==s2[1]) { //同一排
			cout<<1;
			if (cr[s1[2]]==cr[s2[2]]) { //同一侧
				cout<<1;
				if (fabs(s1[2]-s2[2])==1) { //相邻
					cout<<1;
				} else {
					cout<<0;
				}
			} else {
				cout<<0<<0;
			}
		} else {
			cout<<0<<0<<0;
		}
	} else {
		cout<<0<<0<<0<<0;
	}

	return 0;
}

