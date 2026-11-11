#include<bits/stdc++.h>
using namespace std;
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
void rd(int &x){
	int f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	x*=f;
}void wr(int x,char end='\n'){
	if(x<0)putchar('-'),x=-x;
	int len=0,s[20];
	if(x==0)s[++len]=0;
	while(x)s[++len]=x%10,x/=10;
	while(len)putchar(s[len--]+'0');
	putchar(end);
}string s,s1,t,t1;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>t>>t1;
	if(s!=t){
		cout<<"0000";
		return 0;
	}cout<<"1";
	int x=0,y=0;
	for(int i=0;i<2;i++)x=x*10+s1[i]-'0',y=y*10+t1[i]-'0';
	if(x!=y){
		cout<<"000";
		return 0;
	}cout<<"1";
	if((s1[2]<='C'&&t1[2]<='C')||(s1[2]>='D'&&t1[2]>='D')){
		cout<<1;
		char c=s1[2],c1=t1[2];
		if(c>c1)swap(c,c1);
		if(c==(c1-1))cout<<1;
		else cout<<0; 
	}else cout<<"00";
	return 0;
} 
