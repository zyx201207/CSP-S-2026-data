#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	bool f=0;
	char ch;
	x=0;
	while(ch=getchar(),(ch<'0'||ch>'9')) if(ch=='-') f=1;
	while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	if(f) x=-x;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar((x%10)+48);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	return 0;
}

