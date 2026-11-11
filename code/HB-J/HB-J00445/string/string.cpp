#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int x[N];
char c[N];
long long ans=0;
deque<pair<char,int>>q;
deque<pair<char,int>>p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&x[i],&c[i]);
	}
	int f=1;
	if(n%2==1)f=2;
	for(int i=1;i<=n/2;i++){
		q.push_back({c[i],x[i]});
	}
	for(int i=n;i>=n/2+f;i--){
		p.push_back({c[i],x[i]});
	}
	while(!q.empty()&&!p.empty()){
		int a=q.front().second,b=p.front().second;
		char y=q.front().first,z=p.front().first;
		q.pop_front(),p.pop_front();
		int minn=min(a,b);
		if(y==z){
			if(a>b){
				a=a-minn;
				q.push_front({y,a});
			}else if(b>a){
				b=b-minn;
				p.push_front({z,b});
			}
		}else if(y!=z){
			ans+=minn;
			if(a>b){
				a=a-minn;
				q.push_front({y,a});
			}else if(b>a){
				b=b-minn;
				p.push_front({z,b});
			}
		}
	}
	if(n%2==1){
		if(q.empty()&&p.empty()){
			cout<<ans;
		}else{
			int a;
			char b;
			if(!q.empty()){
				a=q.front().second;
				b=q.front().first;
			}else{
				a=p.front().second;
				b=p.front().first;
			}
			if(b==c[n/2+1]){
				cout<<ans;
			}else{
				ans=ans+a;
				cout<<ans;
			}
		}
	}else{
		cout<<ans;
	}
	return 0;
}
