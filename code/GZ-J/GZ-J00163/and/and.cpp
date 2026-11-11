//GZ-J00163 遵义市汇川区第二小学 韩铭钊 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
stack<int> s;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s.push(a);
	}
	for(int i=(1<<30);i>0;i>>=1){
		stack<int> b,c;
		int sum=0;
		while(!s.empty()){
			if(s.top()&i){
				sum++;
				b.push(s.top());
			}
			c.push(s.top());
			s.pop();
		}
		if(sum>=m){
			while(!b.empty()){
				s.push(b.top());
				b.pop();
			}
			ans+=i;
		}else{
			while(!c.empty()){
				s.push(c.top());
				c.pop();
			}
		}
	}
	cout<<ans;
    return 0;
}


