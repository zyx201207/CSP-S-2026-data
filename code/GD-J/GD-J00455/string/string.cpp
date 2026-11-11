#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,sum,num[N],ans;
double k;
char ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i]>>ch[i],num[i]+=num[i-1];
	k=(num[n]+1.0)/2;
	int si=upper_bound(num+1,num+n+1,k)-num;
//	cout<<si<<'\n';
	int st=(num[n]&1)?k+1:k+0.5;
	for(int i=si;i<=n;i++){
		if(i!=si) st=num[i-1]+1;
		int en=num[i],dst=num[n]+1-st,den=num[n]+1-en;
		int t1=lower_bound(num+1,num+n+1,den)-num;
		int t2=lower_bound(num+1,num+n+1,dst)-num;
//		cout<<ch[i]<<den<<' '<<dst<<'\n';
//		cout<<st<<' '<<en<<'\n';
//		cout<<t1<<' '<<t2<<'\n';
//		cout<<num[t1]<<' '<<num[t2]<<'\n';
//		cout<<"\n\n";
		for(int j=t1;j<=t2;j++){	
			if(ch[i]!=ch[j]){
//				cout<<ch[j]<<'\n';
//				cout<<j<<'\n';
				if(j==t1) ans+=min(dst,num[t1])-den+1;
				else if(j==t2) ans+=dst-num[t2-1];
				else ans+=num[j]-num[j-1];
			}
		}
//		cout<<ans<<"\n\n";
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


6
2 c
1 a
2 b
2 a
1 e
1 d
*/

