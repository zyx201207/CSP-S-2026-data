#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,a[N];
long long cntl,cnt,ans,len;
char c[N];
struct node{
	int sum;
	char ch;
};
stack<node> stk1,stk2,s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	cnt=1;
	cntl=a[1];
	s.push({a[1],c[1]});
	while(cntl<len/2){
		cnt++;
		s.push({a[cnt],c[cnt]});
		cntl+=a[cnt];
	}
	int p=s.top().sum;
	char q=s.top().ch;
	s.pop();
	if(cntl-p==len/2){
		stk2.push({p,q});
	}
	else {
		int o=(len/2)-(cntl-p);
		stk1.push({o,q});
		stk2.push({p-o,q});
	}
	while(!s.empty()){
		node y=s.top();
		stk1.push({y});
		s.pop();
	}
	for(int i=cnt-1;i<=n;i++){
		stk2.push({a[i],c[i]});
	}
	while(!stk1.empty()&&!stk2.empty()){
		int cur1=stk1.top().sum,cur2=stk2.top().sum;
		char wbg=stk1.top().ch,gr=stk2.top().ch;
		stk1.pop();
		stk2.pop();
		if(wbg!=gr){
			ans+=min(cur1,cur2);
			if(cur1<cur2){
				stk2.push({cur2-cur1,gr});
			}
			else if(cur1>cur2){
				stk1.push({cur1-cur2,wbg});
			}
		}
		else {
			if(cur1<cur2){
				stk2.push({cur2-cur1,gr});
			}
			else if(cur1>cur2){
				stk1.push({cur1-cur2,wbg});
			}
		}
	}
	cout<<ans;
	return 0;
} 
