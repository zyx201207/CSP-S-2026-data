#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans,sum;
char d;
struct node{
	char c;
	long long ct;
};


deque<node>q;
int main (){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>x>>d;
	sum+=x;
	if(i>1){
	if(d==q.back().c){
			q.back().ct+=x;
		}else{
			q.push_back({d,x});
		}
	}
	else if(i==1)
	q.push_back({d,x});
}

	while(!q.empty()){
		if(q.size()==1){
			cout<<ans;
			return 0;
		}
		node t=q.front();
		node e=q.back();
		if(t.c==e.c){
			if(t.ct>e.ct){
				q.front().ct-=e.ct;
				q.pop_back();
			}else if(t.ct<e.ct){
				q.back().ct-=t.ct;
				q.pop_front();
			}else{
					q.pop_back();
						q.pop_front();
			}
		}else{
			if(t.ct>e.ct){
				q.front().ct-=e.ct;
				q.pop_back();
				ans+=e.ct;
			}else if(t.ct<e.ct){
				q.back().ct-=t.ct;
				q.pop_front();
				ans+=t.ct;
			}else{
				ans+=t.ct;
					q.pop_back();
						q.pop_front();
			}
		}
	}
cout<<ans;
return 0;

}


