#include<bits/stdc++.h>
using namespace std;
#define int long long

bool tc;//同一节车厢 
bool tp;//同一排 
bool tctpyc;//同排同列一侧 
bool xl;//相邻 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a[0]==c[0] and a[1]==c[1])tc=1;
	else tc=0;
	cout<<tc;
	if(tc==1 and b[0]==d[0] and b[1]==d[1])tp=1;
	else tp=0;
	cout<<tp;
	if(tc==1 and tp==1){
		if(b[2]=='D' and d[2]=='A' or b[2]=='A' and d[2]=='D' or b[2]=='A' and d[2]=='F' or b[2]=='F' and d[2]=='A' or b[2]=='D' and d[2]=='B' or b[2]=='B' and d[2]=='D' or b[2]=='F' and d[2]=='B' or b[2]=='B' and d[2]=='F' or b[2]=='C' and d[2]=='D' or b[2]=='D' and d[2]=='C' or b[2]=='C' and d[2]=='F' or b[2]=='F' and d[2]=='C'){
			tctpyc=0;
		}
		else tctpyc=1;
	}
	cout<<tctpyc;
	if(tc==1 and tp==1 and tctpyc==1){
		if(b[2]=='A' and d[2]=='C' or b[2]=='C' and d[2]=='A')xl=0;
		else xl=1;
	}
	cout<<xl;
	return 0;
} 
