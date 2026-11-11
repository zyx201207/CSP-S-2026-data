//and
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
__int128 read(){
	long long f=1;
	__int128 res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		int kk=ch-48;
		res=res*10+kk;
		ch=getchar();
	}
	return res*f;
}
void print(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
bool vis[264444];
__int128 work(__int128 x,__int128 y){
	string s1,s2;
	s1.clear(),s2.clear();
	while(x){
		char kk=x%2+48;
		x/=2;
		s1+=kk;
	}
	while(y){
		char kk=y%2+48;
		y/=2;
		s2+=kk;
	}
	while(s1.size()>s2.size()){
		s2+='0';
	}
	while(s1.size()<s2.size()){
		s1+='0';
	}
	string s;
	s.clear();
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(__int128 i=0;i<s1.size();i++){
		bool kk1=s1[i]-48,kk2=s2[i]-48;
		__int128 kk=kk1&&kk2;
		char kkk=kk+48;
		s+=kkk; 
	}
	__int128 res=0;
	for(long long i=0;i<s.size();i++){
		res+=(pow(2,s.size()-i-1)*(s[i]-48));
	}
	return res;
}
__int128 ans=-0x3f3f3f3f3f3f3f3f;
long long a[264444];
__int128 n,m;
void dfs(__int128 pos,__int128 cnt,__int128 now){
	if(pos==n){
		if(cnt!=m)return;
		ans=max(ans,now);
		return;
	}
	vis[pos+1]=1;
	dfs(pos+1,cnt+1,work(now,a[pos+1]));
	vis[pos+1]=0;
	dfs(pos+1,cnt,now);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	__int128 n;
	n=read(),m=read();
	for(__int128 i=1;i<=n;i++)cin>>a[i]; 
	dfs(0,0,2147483647);
	print(ans);
}
