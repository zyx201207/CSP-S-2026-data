#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,ans;
vector<pair<ll,char>> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	char last=0; ll tot=0;
	for(int i=1; i<=n; ++i){
		ll x; char y;
		cin>>x>>y;
		if(s.empty()) s.push_back({x,y});
		else{
			if(y==last){
				s[s.size()-1].first+=x;
			}
			else{
				s.push_back({x,y});
			}
		}
		last=y;
		tot+=x;
	}
	if(s.size()==1){
		cout<<0; return 0;
	}
	ll lnum=0,rnum=0; char lchar,rchar;
	int head=0,tail=s.size()-1;
	while(1){
		//如果相等那么就指着同一个，如果大于那就是取完了 
		if(head>tail)break;
		if(lnum==0&&rnum==0){
			if(head==tail)break;
			lnum=s[head].first,lchar=s[head].second;
			head++;
			rnum=s[tail].first,rchar=s[tail].second;
			tail--;
		}
		else if(lnum==0){
			lnum=s[head].first,lchar=s[head].second;
			head++;
		}
		else if(rnum==0){
			rnum=s[tail].first,rchar=s[tail].second;
			tail--;
		}
//		cout<<"Get! lnum|lchar|rnum|rchar:"<<
//		lnum<<"|"<<lchar<<"|"<<rnum<<"|"<<rchar<<"\n";
		ll can_remove=min(lnum,rnum);
		if(lchar==rchar){
			lnum-=can_remove; rnum-=can_remove;
			continue;
		}
		else{
			lnum-=can_remove; rnum-=can_remove;
			ans+=can_remove;
			continue;
		}
	}
	cout<<ans;
}
#if 0
//表达一下对学会的深切爱意
int a[8]={103,121,108,123,57,135,148,166};
int main(){
	for(int i=0; i<8; ++i)cout<<(char)(a[i]-(i+1)*(i+1));
} 
#endif
/*
让我想想……
其实
只需要看S[i]和S[len-i]不相同的个数即可
但太大了，O(n)会超时，最多也只能68pts
那么
我们应该是……
双指针
对的
如果到最后一个还剩下，vector却已经空的时候
那么就不用判了，因为都回文 
9:37 pass big example(string5/6.in)
oh I spent 1h on it!!!
----------------------------
我要CSP 1=!!! 
然后回去打
Minecraft, Phigros, Rhythm Doctor, A Dance Of Fire and Ice, Bilibili...... 
科尔的歌都豪庭！
Phi Chapter9牛逼！ 
*/








































//

