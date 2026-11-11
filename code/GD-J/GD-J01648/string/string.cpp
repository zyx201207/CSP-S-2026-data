#include<bits/stdc++.h>
using namespace std;
struct str{
	int len;
	char a;
}z[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	bool p=true;
	char tmp;
	scanf("%d",&n);
	scanf("%d%c",&z[1].len,&z[1].a);
	tmp=z[1].a;
	for(int i=2;i<=n;i++){
		scanf("%d%c",&z[i].len,&z[i].a);
		if(z[i].a!=tmp)p=false;
	}
	if(p){
		cout<<"0";
		return 0;
	}
	
	return 0;
}

