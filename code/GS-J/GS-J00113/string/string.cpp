#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for (int i = 0 ;i < n;i++){
		cin >> s;
		if (n==1){
		cout <<0;
	}
	else
	{
		cout << s[1]-s[1]/2	;
		}
	}
	
	

	
}
