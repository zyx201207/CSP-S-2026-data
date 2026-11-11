#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+5,mod=1e9+7;
inline ll read(){
	ll f=1,tot=0;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return f*tot;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
	}else if(x<10){
		putchar(x-'0');
	}else{
		write(x/10);
		putchar(x%10-'0');
	}
	return ;
}
void solve(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		putchar('1');
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			putchar('1');
			if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D')&&(s4[2]>='D')){
				putchar('1');
				if(abs(s2[2]-s4[2])<=1){
					puts("1");
				}else{
					puts("0");
				}
			}else{
				puts("00");
			}
		}else{
			puts("000");
		}
	}else{
		puts("0000");
	}
	return ;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	//T=read();
	while(T--)solve();
	return 0;
} 
