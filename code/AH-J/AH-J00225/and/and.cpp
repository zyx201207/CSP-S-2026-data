#include<bits/stdc++.h>
using namespace std;
const int dd=2e5+5;
int n,k;
int sz;
string a[dd],tmp[dd];
string gettwo(int x)
{
	string res="";
	while(x>0){
		res=char(x%2+'0')+res;
		x/=2;
	}
	int len=res.size();
	while(len<31){
		res='0'+res;
		len++;
	}
	return res;
}
int read()
{
	int x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		int x=read();
		a[i]=gettwo(x);
	}
	sz=n;
	string ans="";
	for(int i=0;i<31;i++){
		int cnt=0;
		for(int j=1;j<=sz;j++) if(a[j][i]=='1') cnt++;
		if(cnt<k) ans=ans+'0';
		else{
			int t=0;
			for(int j=1;j<=sz;j++) if(a[j][i]=='1') tmp[++t]=a[j];
			for(int j=1;j<=t;j++) a[j]=tmp[j];
			sz=t;
			ans=ans+'1';
		}
	}
	long long m=0;
	for(int i=0;i<31;i++) m=m*2ll+ans[i]-'0';
	write(m);
	return 0;
}
