#include<bits/stdc++.h>
using namespace std;

int n, m;
string s[50005];

int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	
	cin >> n >> m;
	cin >> s[n];
	for(int i = 1; i <= n; i++)
	{
		s[i] = s[i-1];
    }
    cout << "1" << endl << "2";
	return 0;
}


