#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans;
struct node{
	long long x;
	char c;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(long long i=0;i<n;i++){
		cin>>s[i].x>>s[i].c;
		sum+=s[i].x;
	}long long m=sum/2;
	long long o=0,p;
	stack<node> st1,st2;
	for(long long i=0;i<n;i++){
		if(o+s[i].x>m){
			p=i;
			if(sum%2==1){
				s[i].x-=(m-o)+1;
			}else{
				s[i].x-=m-o;
			}if(m-o!=0)st1.push({m-o,s[i].c});
			break;
		}else{
			st1.push({s[i].x,s[i].c});
		}o+=s[i].x;
	}o=0;
	for(long long i=n-1;i>=p;i--){
		st2.push({s[i].x,s[i].c});
	}
	while(!st1.empty()&&!st2.empty()){
		node s1=st1.top(),s2=st2.top();
		st1.pop();
		st2.pop();
		if(s1.c!=s2.c){
			ans+=min(s1.x,s2.x);
			if(s1.x>s2.x)st1.push({s1.x-s2.x,s1.c});
			else if(s1.x<s2.x)st2.push({s2.x-s1.x,s2.c});
		}else if(s1.c==s2.c){
			if(s1.x>s2.x)st1.push({s1.x-s2.x,s1.c});
			else if(s1.x<s2.x)st2.push({s2.x-s1.x,s2.c});
		}
	}cout<<ans;
	return 0;
}
