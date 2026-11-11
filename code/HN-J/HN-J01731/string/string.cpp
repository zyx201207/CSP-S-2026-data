#include<bits/stdc++.h>
#define MAXN 200010 
using namespace std;
typedef long long ll;
struct String{
	int sum;
	char c;
	String(int sum=0,char c=0){
		this->sum=sum;
		this->c=c; 
	}
};
int n,a[MAXN];
char c[MAXN];
deque<String> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		cin>>c[i];
		q.push_back(String(a[i],c[i]));
	}
	ll ans=0;
	while(q.size()>1){
		int cut=min(q.front().sum,q.back().sum);
		q.front().sum-=cut;
		q.back().sum-=cut;
		if(q.front().c^q.back().c){
			ans+=cut;
		}
		if(!q.empty()&&q.front().sum==0){
			q.pop_front();
		}
		if(!q.empty()&&q.back().sum==0){
			q.pop_back(); 
		}
	}
	printf("%lld",ans);
	return 0;
}

