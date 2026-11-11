#include<iostream>
typedef long long ll;
using namespace std;
ll num[200005];
char ch[200005];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>num[i]>>ch[i];
	ll lnum=num[1],rnum=num[n],lin=1,rin=n;
	char lch=ch[1],rch=ch[n];
	while(lin!=rin){
		if(lnum>rnum){
			if(lch!=rch)ans+=lnum-rnum;
			lnum-=rnum;rnum=0;
		}else{
			if(lch!=rch)ans+=rnum-lnum;
			rnum-=lnum;lnum=0;
		}
		if(!lnum){
			++lin;
			lnum=num[lin];
			lch=ch[lin];
		}
		if(!rnum){
			--rin;
			rnum=num[rin];
			rch=ch[rin];
		}
	}
	cout<<ans;
	return 0;
}
