#include<bits/stdc++.h>
using namespace std;
string s[4];
int a[3],b,c;
char z,y;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s[1];
cin>>a[1];
cin>>z;
cin>>s[2];
cin>>a[2];
cin>>y;
b=z;
c=y;
if(s[1]==s[2]){cout<<1;
if(a[1]==a[2]){cout<<1;
if(b==67 and c==68 or b==68 and c==67){cout<<"00";
}else {cout<<1;
	if(b+1==c or b-1==c){cout<<1;
}else cout<<0;
	}
}else cout<<"000";
}else cout<<"0000";
return 0;
}
