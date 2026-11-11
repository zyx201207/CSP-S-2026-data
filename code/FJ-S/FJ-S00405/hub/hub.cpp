#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll read(){
	ll ans=0,w=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-'){
			w=-w;
		}
		s=getchar();
	}
	while(isdigit(s)){
		ans=(ans<<3LL)+(ans<<1LL)+(s^48);
		s=getchar(); 
	}
	return ans*w;
}

int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);

	
	return 0;
}
