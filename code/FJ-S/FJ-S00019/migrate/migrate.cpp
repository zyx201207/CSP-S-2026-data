#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
inline read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'0'||ch<'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long c,T,n,d,id[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	while(T--){
		cin>>n>>d;
		long long cha;
		for(int i=1;i<=n;i++)cin>>id[i];
		cha=id[2]-id[1];
		if(c==11||c==12){
			long long tot=0;
			if(cha<=d/2){
				tot+=n-2;
			}
			for(int i=3;i<=n;i++){
				if(cha>d/i)break;
				tot+=n-i;
			}
			cout<<tot;
		}
	}
	return 0;
}

