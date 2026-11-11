#include<bits/stdc++.h>
using namespace std;

int in(){
	int f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}
