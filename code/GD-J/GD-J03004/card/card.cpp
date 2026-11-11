#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    int a,b;
    cin >> a >> b;
    int s[a+5];
    for(int i=1;i<=a;i++){
    	cin >> s[i];
	}
	cout << a << " " << b <<" "  << s[1];
    return 0;
}
