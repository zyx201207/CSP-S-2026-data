#include <bits/stdc++.h>

using namespace std;
typedef int ll;
string c1, c2, s1, s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	if(c1 != c2){
		
		cout << "0000";
		return 0;
	}
	
	string z1 = s1.substr(0,2);
	string z2 = s2.substr(0,2);
	if(z1 != z2){
		cout << "1000";
		return 0;
	}
	char q1 = s1[s1.size()-1];
	char q2 = s2[s2.size()-1];
	
	if((('A'<=q1&&q1<='C')&&('D'<=q2&&q2<='E')
	)||(('A'<=q2&&q2<='C')&&('D'<=q1&&q1<='E')
	)){
		
		cout<<"1100";
		//cout<<q1<<'a'<<q2;
		
		return 0;
	}
	
	ll p1 = (q1-'0');
	ll p2 = (q2-'0');
	
	if((p1==p2+1)||(p1+1==p2)){
		cout << "1111";
	}else{
		cout<<"1110";
	}
	

	return 0;	
}
