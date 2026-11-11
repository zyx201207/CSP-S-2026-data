#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f; 
}
long long mi(long a,long b){
	if(a<=b)return a;
	return b;
}
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	c=read();
	t=read();
	while(t--){
		long long ans=0x3f3f3f3f;
		long long a,b;
		a=read();
		b=read();
		for(int i=1;i<=a-1;i++){
			long long q,p;
			q=read();
			p=read();
			ans=mi(ans,mi(q,p));
		}
		cout<<ans<<endl;
	}
	return 0;
}
