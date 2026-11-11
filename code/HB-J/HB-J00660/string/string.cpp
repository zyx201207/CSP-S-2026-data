#include<bits/stdc++.h>
using namespace std;
long long ans=0;
struct edge{
	long long a;
	char c;
};	
deque<edge>q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;    
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		q.push_front({a,c});
	}	
	while(q.size()>1){
		edge x=q.front(),y=q.back();
		q.pop_front();
		q.pop_back();
		long long a1=x.a,a2=y.a;
		char c1=x.c,c2=y.c;
		if(c1!=c2)ans+=min(a1,a2);
		long long miss=min(a1,a2);
		a1-=miss;a2-=miss;
		if(a1>0){
			q.push_front({a1,c1});
		}
		if(a2>0){
			q.push_back({a2,c2});
		}		
	}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
