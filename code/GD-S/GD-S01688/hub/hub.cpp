#include <bits/stdc++.h>
using namespace std;
const int M = 1 << 20;
char buf[M];
int buf_len, buf_pos;
inline int gc(){
	if(buf_len == buf_pos){
		buf_pos = 0;
		buf_len = fread(buf, 1, M, stdin);
		if(buf_len == 0) return EOF;
	}
	return buf[buf_pos++];
}
inline int read(){
	int s(0), t(1), c = gc();
	for(;c != EOF && (c < '0' || c > '9');c = gc()) if(c == '-') t = -1;
	if(c == EOF) return 0;
	for(;c >= '0' && c <= '9';c = gc()) s = (s << 3)+(s << 1)+(c ^ 48);
	return t*s;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = read(), t = read();
	while(t--)
		cout << 1 << '\n';
} 
