#include<bits/stdc++.h>
using namespace std;
char a[5]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	char s1s=s1[2],s2s=s2[2];
	if(s1s==a[0]){
		if(s2s==a[1]) cout << "11";
		else if(s2s==a[2]) cout << "10";
		else{
			cout << "00";
			return 0;
		}
	}
	else if(s1s==a[1]){
		if(s2s==a[0]||s2s==a[2]) cout << "11";
		else{
			cout << "00";
			return 0;
		}
	}
	else if(s1s==a[2]){
		if(s2s==a[1]) cout << "11";
		else if(s2s==a[0]) cout << "10";
		else{
			cout << "00";
			return 0;
		}
	}
	else if(s1s==a[3]){
		if(s2s==a[4]) cout << "11";
		else{
			cout << "00";
			return 0;
		}
	}
	else{
		if(s2s==a[3]) cout << "11";
		else{
			cout << "00";
			return 0;
		}
	}
	return 0;
}
