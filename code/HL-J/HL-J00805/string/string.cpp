#include <bits/stdc++.h>
using namespace std;
int n,sum;
char s;
string ch;
bool c(string ch1){
	string ch2 = ch1;
	reverse(ch1.begin(),ch1.end());
	return ch2 == ch1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
    	int n1;
    	cin >> n1 >> s;
    	while(n1--){
    		ch+=s;
		}
		
	}	
	if(c(ch)){
		cout <<"0";
		
	}
	int len = ch.size();
	for(int i = 0;i <= len / 2;i++){
		if(ch[i] != ch[ch.size() - i - 1]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
