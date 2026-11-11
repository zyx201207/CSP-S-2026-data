#include<bits/stdc++.h>
#define ll long long
#define rt return
#define ffor(a,b,c,d) for(int (a)=(b);(a)<(c);(a)+=(d))
using namespace std;
const int N=2e5+10;
struct cn{
	int a;
	char c;
}ax[N];
string st,at,ct;
int n,x,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ffor(i,0,n,1){
		cin>>ax[i].a>>ax[i].c;
	}
	bool f=0;
	for(int i=0;i*i<=n;i++){
		if(ax[i].a!=ax[n-i-1].a||ax[i].c!=ax[n-i-1].c){
			f=1;
			break;
		}
	}
	if(!f){
		cout<<0;
		rt 0;
	}
	ffor(i,0,n,1){
		ffor(j,0,ax[i].a,1){
			st+=ax[i].c;
		}
	}
	at=st;
	reverse(at.begin(),at.end());
	if(st==at){
		cout<<0;
		rt 0;
	}
	x=st.size()/2;
	at=st.substr(0,x);
	ct=st.substr(x+1,x);
	reverse(ct.begin(),ct.end());
	ffor(i,0,x,1){
		if(at[i]!=ct[i]){
			ans++;
		}
	}
	cout<<ans;
	rt 0;
}
//code by Rufory
//FJ-J01100
