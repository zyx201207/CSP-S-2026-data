#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define lowbit(x) x&(-x)
#define pii pair<int,int>
using namespace std;

int c1,c2;
string s1,s2;

void Code(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)printf("1");
	else{printf("0000");return ;}
	int id1=(s1[0]-'0')*10+(s1[1]-'0'),id2=(s2[0]-'0')*10+(s2[1]-'0');
	if(id1==id2)printf("1");
	else{printf("000");return ;}
	char ch1=s1[2],ch2=s2[2];
	if((ch1=='A' and (ch2=='B' or ch2=='C')) or (ch1=='B' and (ch2=='A' or ch2=='C')) or (ch1=='C' and (ch2=='A' or ch2=='B')))printf("1");
	else if((ch1=='D' and ch2=='E') or (ch1=='E' and ch2=='D'))printf("1");
	else{printf("00");return ;}
	if(ch1>ch2)swap(ch1,ch2);
	if((ch1=='A' and ch2=='B') or (ch1=='B' and ch2=='C') or (ch1=='D' and ch2=='E'))printf("1");
	else printf("0");
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t;t=1;
	while(t--)Code();
	return 0;
} 

