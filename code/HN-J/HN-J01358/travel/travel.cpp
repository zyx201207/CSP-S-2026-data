#include<bits/stdc++.h>
using namespace std;
#define MAXN 110

inline void read(int &x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

void fileIO(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

string c1,s1,c2,s2;
char p1,p2;
int n1,n2;
bool flag[MAXN];
void init(){
	int len1=s1.size(),len2=s2.size();
	for(int i=0;i<len1-1;i++)n1=n1*10+s1[i]-'0';
	for(int i=0;i<len2-1;i++)n2=n2*10+s2[i]-'0';
	p1=s1[len1-1];p2=s2[len2-1];
	for(char a='A';a<='C';a++)flag[a-'A']=0;
	flag['D'-'A']=flag['F'-'A']=1;
}

int main(){
	fileIO("travel");
	cin>>c1>>s1>>c2>>s2;
	init();
	
	if(c1==c2)putchar('1');
	else{
		printf("0000");
		return 0;
	}
	
	if(n1==n2)putchar('1');
	else{
		printf("000");
		return 0;
	}
	
	if(flag[p1-'A']==flag[p2-'A'])putchar('1');
	else{
		printf("00");
		return 0;
	}
	
	if(((!flag[p1-'A'])&&(!flag[p2-'A'])&&abs(p1-p2)==1)||(flag[p1-'A']&&flag[p2-'A']))
	    putchar('1');
	else printf("0"); 
	return 0;
}
