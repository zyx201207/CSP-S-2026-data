/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dd double
#define pii pair<int,int>
#define pll pair<ll,ll>
ll read(){
	char ch=getchar();
	int f=1;
	ll x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
string a,b,c,d;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	

	cin>>a>>b>>c>>d;
	int x=(a[0]-'0')*10+a[1]-'0';
	int y=(c[0]-'0')*10+c[1]-'0';
	ans+=(x==y)+'0';
	if(ans[0]=='1'){
	x=(b[0]-'0')*10+b[1]-'0';
	y=(d[0]-'0')*10+d[1]-'0';
	ans+=(x==y)+'0';
	if(x==y){
		if(b[2]<='C'){
			ans+=(d[2]<='C')+'0';
		}else{
			ans+=(d[2]>'C')+'0';
		}
	}else ans+='0';
	if(ans[2]=='1'){
		if(b[2]<='C'){
			ans+=(abs(b[2]-d[2])==1)+'0';
		}else{
			ans+='1';
		}
	}else ans+='0';
		
	}else{
		ans+="000";
	}
	cout<<ans;
	return 0;
}

