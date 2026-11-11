#include<bits/stdc++.h>
using namespace std;
char c1,s1,c2,s2,num;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
        num = num+'1';
	}
	else{
        num = num+'0';
        }
    cout<<num<<endl;
	return 0;
	}
