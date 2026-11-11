#include<bits/stdc++.h>
using namespace std;
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-'){ f=-1; }ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(int x){ if(x<0){ putchar('-');x=-x; }int cnt=0;char c[23];do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); }putchar(' '); }
const int mod=998244353,N=1000005;
int n,a[N<<1];
string s1,s2,t1,t2;
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1){
		cout<<'1';
		if(s2[0]==t2[0]&&s2[1]==t2[1]){
			cout<<'1';
			if((s2[2]<='C')==(t2[2]<='C')){
				cout<<'1';
				if(s2[2]=='B'||s2[2]=='D'||t2[2]=='B'||t2[2]=='D')cout<<'1';
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
