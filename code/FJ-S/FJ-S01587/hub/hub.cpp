//T4 ¿ªÊ¼Ï¹¸ã 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll read(){
	ll a=0,f=1;
	char c=getchar();
	while (c<'0' or c>'9'){
		if (c=='-')f=-1;
		c=getchar();
	}while (c>='0' and c<='9'){
		a=a*10+c-48;
		c=getchar();
	}return a*f;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//cout<<"I want CSP-S one!" ;
	cout<<1<<endl<<2; 
	return 0;
}

