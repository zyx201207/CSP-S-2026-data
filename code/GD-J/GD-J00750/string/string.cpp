#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+500;
int n = 0;
int cnt = 0;
unsigned long long l = 0;
int a[N];
char c[N];
struct node{
	unsigned long long x;
	//x -> num
	char c;
}str[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		if(c[i]==c[i-1]){
			str[cnt].x+=a[i];
		}else{
			str[++cnt].x+=a[i];
			str[cnt].c = c[i];
		}
		l+=c[i];
	}
	unsigned long long left = 1;
	unsigned long long lefti = 1;
	unsigned long long right = l;
	unsigned long long righti = cnt;
	unsigned long long ans = 0;
	if(l % 2 == 0){
		unsigned long long ll = str[lefti].x;
		unsigned long long rl = str[righti].x;
		char lc = str[lefti].c;
		char rc = str[righti].c;
		for(;left < right && lefti<=righti;){
			bool fl = !(lc == rc); 
			if(ll > rl){
				left += rl;
				right -= rl;
				
				righti --;
				
				ans += fl * rl;
				
				ll -= rl;
				
				rl = str[righti].x;
				rc = str[righti].c;
			}
			else if(ll == rl){
				left += rl;
				right -= rl;
				
				lefti ++;
				righti--;
				
				ans += fl * rl;
				
				ll -= rl;
				
				rl = str[righti].x;
				ll = str[lefti].x;
				lc = str[lefti].c;
				rc = str[righti].c;
			}
			else{
				left += ll;
				right -=ll;
				
				lefti++;
				
				ans += fl * ll;
				
				rl -= ll;
				
				ll = str[lefti].x;
				lc = str[lefti].c;
			}
		}
	}
	else{
		unsigned long long ll = str[lefti].x;
		unsigned long long rl = str[righti].x;
		char lc = str[lefti].c;
		char rc = str[righti].c;
		for(;left + 1 < right && lefti<=righti;){
			bool fl = !(lc == rc); 
			if(ll > rl){
				left += rl;
				right -= rl;
				
				righti --;
				
				ans += fl * rl;
				
				ll -= rl;
				
				rl = str[righti].x;
				rc = str[righti].c;
			}
			else if(ll == rl){
				left += rl;
				right -= rl;
				
				lefti ++;
				righti--;
				
				ans += fl * rl;
				
				ll -= rl;
				
				rl = str[righti].x;
				ll = str[lefti].x;
				lc = str[lefti].c;
				rc = str[righti].c;
			}
			else{
				left += ll;
				right -=ll;
				
				lefti++;
				
				ans += fl * ll;
				
				rl -= ll;
				
				ll = str[lefti].x;
				lc = str[lefti].c;
			}
		}
	}
		
	cout << ans;
	return 0;
}
//aabbc
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


5
10 a
78 a
91 a
7891 c
666666 a

5
1 a
1 b
1 c
1 a
1 b
*/
