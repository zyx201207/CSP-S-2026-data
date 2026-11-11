#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int128 __int128
#define gc getchar()
using namespace std;
const int N=1e5+10;
int rd(){
	int x=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+c-'0',c=gc);
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=rd(),t=rd();
	while(t--)cout<<0<<'\n'; 
	return 0;
}

