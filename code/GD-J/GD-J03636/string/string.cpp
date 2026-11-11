#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll n,L;
struct node{
	ll num;
	char c;
};
node ar[N],l[N],r[N];
ll lc,rc,pos1,pos2,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i].num>>ar[i].c;
		L+=ar[i].num;
	}
	
	pos1=L/2;
	for(int i=1;i<=n;i++){
		if(pos1>=ar[i].num){
			l[++lc]={ar[i].num,ar[i].c};
			pos1-=ar[i].num;
		}
		else if(pos1){
			l[++lc]={pos1,ar[i].c};
			break;
		}
	}
	pos1=L/2;
	for(int i=n;i>=1;i--){
		if(pos1>=ar[i].num){
			r[++rc]={ar[i].num,ar[i].c};
			pos1-=ar[i].num;
		}
		else if(pos1){
			r[++rc]={pos1,ar[i].c};
			break;
		}
	}
	ll l1=0,r1=0;
	pos1=0,pos2=0;
	ans=L/2;
	char lstl,lstr;
//	cout<<lc<<" "<<rc;
	while(pos1<lc||pos2<rc){
		while(l1<=r1&&pos1<lc){
			++pos1;
			if(l[pos1].c==lstr){
				if(l1+l[pos1].num>=r1){
					ans-=r1-l1;
				}
				else{
					ans-=l[pos1].num;
				}
			}
			l1+=l[pos1].num;
			lstl=l[pos1].c;
		}
		while(r1<=l1&&pos2<rc){
			++pos2;
			if(r[pos2].c==lstl){
				if(r1+r[pos2].num>=l1){
					ans-=l1-r1;
				}
				else{
					ans-=r[pos2].num;
				}
			}
			r1+=r[pos2].num;
			lstr=r[pos2].c;
		}
		//if(l1==L/2&&r1==L/2) break;
		//cout<<pos1<<" "<<pos2;
	}
	cout<<ans;

	return 0;
}

