#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
string a,b,c,d;
int a1,b1,c1,d1;
char p1,p2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]=='0') a1=a[1]-'0';
	else a1=(a[0]-'0')*10+a[1]-'0';
	if(c[0]=='0') c1=c[1]-'0';
	else c1=(c[0]-'0')*10+c[1]-'0';
	if(a1==c1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]=='0') b1=b[1]-'0';
	else b1=(b[0]-'0')*10+b[1]-'0';
	if(d[0]=='0') d1=d[1]-'0';
	else d1=(d[0]-'0')*10+d[1]-'0';
	if(b1==d1){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}p1=b[2],p2=d[2];
	if(('A'<=p1&&p1<='C'&&'A'<=p2&&p2<='C')||(p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if(p1!='D'&&p1!='F'&&(p1+1==p2||p1-1==p2)){
		cout<<1;
	}else if((p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')){
		cout<<1;
	}else cout<<0;
    return 0;
} 
//T1 ACin 8:53
