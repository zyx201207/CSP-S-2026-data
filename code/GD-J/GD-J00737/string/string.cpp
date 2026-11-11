#include<bits/stdc++.h>
using namespace std;
struct wyt{
	long long ct;
	string col;
}awa[200005];
long long tt,dd;
long long ans,n;
long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	tt=1;
	dd=n;
	for(long long i=1;i<=n;i++){
		long long a;
		string s;
		a=read();
		cin>>s;
		awa[i].ct=a;
		awa[i].col=s;
	}
	while(tt<dd){
		if(awa[tt].col==awa[dd].col){
			long long mi=min(awa[tt].ct,awa[dd].ct);
			awa[tt].ct-=mi;
			awa[dd].ct-=mi;
			if(awa[tt].ct==0)tt++;
			if(awa[dd].ct==0)dd--;
			continue;
		}
		long long mi=min(awa[tt].ct,awa[dd].ct);
		awa[tt].ct-=mi;
		awa[dd].ct-=mi;
		if(awa[tt].ct==0)tt++;
		if(awa[dd].ct==0)dd--;
		ans+=mi;
	}
	cout<<ans;
	return 0;
}
