#include<bits/stdc++.h>//9:34finish样例全过
#define int long long
using namespace std;
int n;
int ans,sum;
struct nod{
	int a;
	char c;
	int l;
}s[200005];
int lnum,rnum;
char lc,rc;
int l,r;
int pl,pr;
int cnt;
signed main(){//关注dlc666嘛，b站叫大破车dlc666 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>s[i].a>>s[i].c;
		s[i].l=sum+1;
		sum+=s[i].a;
//		cout<<"sum="<<sum<<endl;
	}
	s[n+1].l=1e18;
	if(sum%2==0){
		l=sum/2,r=sum/2+1;
	}else{
		l=r=sum/2+1;
	}
//	cout<<l<<' '<<r<<endl;
	for(int i=1;i<=n+1;++i){
//		cout<<':'<<i<<' '<<s[i].l<<endl;
		if(!pl&&s[i].l>l){
			pl=i-1;
		}
		if(!pr&&s[i].l>r){
			pr=i-1;
			break;
		}
	}
	lc=s[pl].c,rc=s[pr].c;
	lnum=l-s[pl].l+1,rnum=s[pr].l+s[pr].a-r;
	if(pl==pr){
		cnt=1;
	}else{
		cnt=2;
	}
//	cout<<pl<<' '<<pr<<endl;
//	cout<<lc<<' '<<rc<<endl;
//	cout<<lnum<<' '<<rnum<<endl;
//	cout<<cnt<<endl;
	while(pl!=1||pr!=n||lc!=rc||lnum!=rnum){
//		cout<<cnt<<' '<<lc<<' '<<rc<<' '<<lnum<<' '<<rnum<<' '<<ans<<' '<<pl<<' '<<pr<<endl;
		if(lc!=rc){
			int cf=min(lnum,rnum);
			ans+=cf;
			lnum-=cf;
			rnum-=cf;
		}else{
			int cf=min(lnum,rnum);
			lnum-=cf;
			rnum-=cf;
		}
		if(lnum==0&&pl>1){
//			cout<<"左边没了"<<endl;
			pl--;
			lc=s[pl].c,lnum=s[pl].a;
			cnt++;
		}
		if(rnum==0&&pr<n){
//			cout<<"右边没了"<<endl;
			pr++;
			rc=s[pr].c,rnum=s[pr].a;
			cnt++;
		}
		if(pl==1&&pr==n&&lnum==0&&rnum==0){
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
/*
2
2 a
3 a
*/
