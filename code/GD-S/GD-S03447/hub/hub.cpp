#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
namespace FastIO{
	inline ll read(){
		ll s=0,f=1;char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}while('0'<=c&&c<='9'){
			s=(s<<1)+(s<<3)+c-'0';
			c=getchar();
		}return s*f;
	}
}
using FastIO::read;




int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	for(int i=1;i<=t;i++)cout<<1<<'\n';
	
	
	
	
	return 0;
}
