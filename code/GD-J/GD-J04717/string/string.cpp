#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long ans=0,cnt=0;
	long long n;
	cin>>n;
	stack <char> suf,pre,time;
	stack <long long> suf2,pre2,time2;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		cnt+=a;
		time.push(c);
		suf.push(c);
		time2.push(a);
		suf2.push(a);
	}
	char x=time.top();
	bool x1=1;
	while(!time.empty()){
		if(time.top()!=x)
			x1=false;
		pre.push(time.top());
		time.pop();
		pre2.push(time2.top());
		time2.pop();
	}
	if(x1){
		cout<<0;
		return 0;
	}
	long long num=0;
	while(num<(cnt/2)){
		char p1=pre.top(),s1=suf.top();
		pre.pop();
		suf.pop();
		long long p2=pre2.top(),s2=suf2.top();
		pre2.pop();
		suf2.pop();
		if(p1!=s1){
			if(p2>s2){
				long long k=p2-s2;
				ans+=s2;
				pre.push(p1);
				pre2.push(k);
				num+=s2;
			}else if(p2<s2){
				long long k=s2-p2;
				ans+=p2;
				suf.push(s1);
				suf2.push(k);
				num+=p2;
			}else if(p2==s2){
				ans+=p2;
				num+=p2;
			}
		}else if(p1==s1){
			if(p2>s2){
				long long k=p2-s2;
				pre.push(p1);
				pre2.push(k);
				num+=s2;
			}else if(p2<s2){
				long long k=s2-p2;
				suf.push(s1);
				suf2.push(k);
				num+=p2;
			}
			else
				num+=p2;
		}
	}
	cout<<ans;
	return 0;
}
