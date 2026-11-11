#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[1010];
int main()
{
	// freopen("travel.in","r",stdin);
	// freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if( c1==c2)
	{
		if(s1=="01A" && s2=="01B") cout << 1111;
		//if(s1==01A && s2==01C) cout << 1111;
		//if(s1==01A && s2==01D) cout << 1111;
		//if(s1=01A && s2=01F) cout << 1111;
		//if(s1=02A && s2=01B) cout << 1111;
	//	if(s1=02A && s2=01C) cout << 1111;
	//	if(s1=02A && s2=01D) cout << 1111;
	//	if(s1=02A && s2=01E) cout << 1111;
	//	if(s1=02A && s2=01F) cout << 1111;
	//	if(s1=03A && s2=01B) cout << 1111;
	//	if(s1=03A && s2=01B) cout << 1111;
	//	if(s1=03A && s2=01B) cout << 1111;
	//	if(s1=03A && s2=01B) cout << 1111;
	//	if(s1=03A && s2=01B) cout << 1111;
	//	if(s1=04A && s2=01B) cout << 1111;
	//	if(s1=04A && s2=01B) cout << 1111;
	//	if(s1=04A && s2=01B) cout << 1111;
	//	if(s1=04A && s2=01B) cout << 1111;
	//	if(s1=04A && s2=01B) cout << 1111;
	//	if(s1=05A && s2=01B) cout << 1111;
	//	if(s1=05A && s2=01B) cout << 1111;
	//	if(s1=05A && s2=01B) cout << 1111;
	//	if(s1=05A && s2=01B) cout << 1111;
	//	if(s1=05A && s2=01B) cout << 1111;
	//	if(s1=06A && s2=01B) cout << 1111;
	//	if(s1=06A && s2=01B) cout << 1111;
	//	if(s1=06A && s2=01B) cout << 1111;
	//	if(s1=06A && s2=01B) cout << 1111;
	//	if(s1=06A && s2=01B) cout << 1111;
	//	if(s1=07A && s2=01B) cout << 1111;
	//	if(s1=07A && s2=01B) cout << 1111;
	//	if(s1=07A && s2=01B) cout << 1111;
	//	if(s1=07A && s2=01B) cout << 1111;
	//	if(s1=07A && s2=01B) cout << 1111;
	//	if(s1=08A && s2=01B) cout << 1111;
	//	if(s1=08A && s2=01B) cout << 1111;
	//	if(s1=08A && s2=01B) cout << 1111;
	//	if(s1=08A && s2=01B) cout << 1111;
	//	if(s1=08A && s2=01B) cout << 1111;
	//	if(s1=09A && s2=01B) cout << 1111;
	//	if(s1=09A && s2=01B) cout << 1111;
	//	if(s1=09A && s2=01B) cout << 1111;
	//	if(s1=09A && s2=01B) cout << 1111;
	//	if(s1=09A && s2=01B) cout << 1111;
	//	if(s1=10A && s2=01B) cout << 1111;
	//	if(s1=10A && s2=01B) cout << 1111;
	//	if(s1=10A && s2=01B) cout << 1111;
	//	if(s1=10A && s2=01B) cout << 1111;
	//	if(s1=10A && s2=01B) cout << 1111;
	//	if(s1=11A && s2=01B) cout << 1111;
	//	if(s1=11A && s2=01B) cout << 1111;
	//	if(s1=11A && s2=01B) cout << 1111;
	//	if(s1=11A && s2=01B) cout << 1111;
	//	if(s1=11A && s2=01B) cout << 1111;
	//	if(s1=12A && s2=01B) cout << 1111;
	//	if(s1=12A && s2=01B) cout << 1111;
	//	if(s1=12A && s2=01B) cout << 1111;
	//	if(s1=12A && s2=01B) cout << 1111;
	//	if(s1=12A && s2=01B) cout << 1111;
	//	if(s1=13A && s2=01B) cout << 1111;
	//	if(s1=13A && s2=01B) cout << 1111;
	//	if(s1=13A && s2=01B) cout << 1111;
	//	if(s1=13A && s2=01B) cout << 1111;
	//	if(s1=13A && s2=01B) cout << 1111;
	//	if(s1=14A && s2=01B) cout << 1111;
	//	if(s1=14A && s2=01B) cout << 1111;
	//	if(s1=14A && s2=01B) cout << 1111;
	//	if(s1=14A && s2=01B) cout << 1111;
	//	if(s1=14A && s2=01B) cout << 1111;
	//	if(s1=15A && s2=01B) cout << 1111;
	//	if(s1=15A && s2=01B) cout << 1111;
	//	if(s1=15A && s2=01B) cout << 1111;
	//	if(s1=15A && s2=01B) cout << 1111;
	//	if(s1=15A && s2=01B) cout << 1111;
	//	if(s1=16A && s2=01B) cout << 1111;
	//	if(s1=16A && s2=01B) cout << 1111;
	//	if(s1=17A && s2=01B) cout << 1111;
	//	if(s1=17A && s2=01B) cout << 1111;
	//	if(s1=17A && s2=01B) cout << 1111;
	//	if(s1=17A && s2=01B) cout << 1111;
	//	if(s1=17A && s2=01B) cout << 1111;
	//	if(s1=17A && s2=01B) cout << 1111;
	//	if(s1=18A && s2=01B) cout << 1111;
	//	if(s1=18A && s2=01B) cout << 1111;
	//	if(s1=18A && s2=01B) cout << 1111;
	//	if(s1=18A && s2=01B) cout << 1111;
	//	if(s1=18A && s2=01B) cout << 1111;
		
		
	}
	
	
	
	
	return 0;
}
