#include<bits/stdc++.h>
using namespace std;
long long n,ans;
typedef pair<long long,char> PII;
deque<PII>a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		a.push_front(make_pair(x,y));
	}while(a.size()>1){
		PII u=a.front(),v=a.back();a.pop_front();a.pop_back();
		if(u.second==v.second){
			a.push_front(make_pair(u.first+v.first,u.second));
		}else{
			if(u.first>v.first)a.push_front(make_pair(u.first-v.first,u.second));
			else if(u.first<v.first) a.push_front(make_pair(v.first-u.first,v.second));
			ans+=min(u.first,v.first);
		}
	}if(a.size()&&!a.front().first%2)ans++;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
