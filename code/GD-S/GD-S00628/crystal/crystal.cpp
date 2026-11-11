#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans=0;
long long a[N];

inline int read(){
	int x=0,f=1;
	int ch=getchar();
	if(!isdigit(ch)) f=-1,ch=getchar();
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return f*x;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<n;i++) a[i]=read();
	sort(a,a+n);
	int lt=n-2,rt=n-1,ans=0,cnt=1,en=0;
	while(lt>=0){
		if(m-(ans+a[rt]-a[lt])>=0){
			ans+=(a[rt]-a[lt]);
			lt--,cnt++;
		}else{
			rt--,ans=0,cnt=1,lt=rt-1;
		}
		en=max(en,cnt);
	}
	cout<<en;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
