#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;
inline int ir(){
	int temp = 0 , t = 1;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if (ch=='-') t=-1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		temp = temp*10 + (ch-'0');
		ch = getchar();
	}
	return temp*t;
}
int main(){
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	return 0;
}