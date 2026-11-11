#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int aa=0,bb=0,cc=0,dd=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<max(a.size(),c.size());++i){
		if(a[i]-'0'!=c[i]-'0')++aa;
	}
	if(!aa){cout<<1;
	}
	else{cout<<"0000";return 0;
	}
    for(int i=0;i<max(b.size(),d.size())-1;++i){
		if(b[i]-'0'!=d[i]-'0')++bb;
	}
	if(!bb){cout<<1;
	}
	else{cout<<"000";return 0;
	}
    if((b[b.size()-1]-'A'<=2 and d[d.size()-1]-'A'>2) or (b[b.size()-1]-'A'>2 and d[d.size()-1]-'A'<=2)){
		cout<<"00";return 0;
}
	else{cout<<1;
	}
    if(abs(b[b.size()-1]-'A'-(d[d.size()-1]-'A'))==1){
	cout<<1;return 0;
	}
	else{cout<<0;
	}
}
