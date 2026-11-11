#include <bits/stdc++.h>
using namespace std;
struct node{
	char ch;
	long long cnt;
	node()=default;
	node(char newch,long long newcnt){
		ch=newch,cnt=newcnt;
	}
}a[200005];
int n;
stack<node> l,r;
__int128 sum,add,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt;
		cin>>a[i].ch;
		sum+=a[i].cnt;
	}
	add=0;
	for(int i=1;i<=n;i++){
		if(add+a[i].cnt>sum/2){
			if(sum/2-add!=0)
				l.push(node(a[i].ch,sum/2-add));
			break;
		}else add+=a[i].cnt,l.push(a[i]);
	}
	add=0;
	for(int i=n;i>=1;i--){
		if(add+a[i].cnt>sum/2){
			if(sum/2-add!=0)
				r.push(node(a[i].ch,sum/2-add));
			break;
		}else add+=a[i].cnt,r.push(a[i]);
	}
	while((!l.empty())&&(!r.empty())){
		node lt=l.top(),rt=r.top();
		if(lt.cnt<=rt.cnt){
			if(lt.ch!=rt.ch) ans+=lt.cnt;
			l.pop(),r.pop();
			if(rt.cnt-lt.cnt!=0)
				r.push(node(rt.ch,rt.cnt-lt.cnt));
		}else{
			if(lt.ch!=rt.ch) ans+=rt.cnt;
			l.pop(),r.pop();
			if(lt.cnt-rt.cnt!=0)
				l.push(node(lt.ch,lt.cnt-rt.cnt));
		}
	}
	cout<<(long long)ans<<"\n";
	return 0;
}
