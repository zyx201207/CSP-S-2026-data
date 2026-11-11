#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll qread(){
	ll rtn=0,fh=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		rtn=rtn*10+c-'0';
		c=getchar();
	}
	return fh*rtn;
}
int main(){
	return 0;
} 
