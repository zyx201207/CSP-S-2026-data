#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str{
	str(int _t=0,char _c='\0'){
		cnt=_t;
		c=_c;
	}
	int cnt;
	char c;
}; 
deque<str> a;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		int t;
		cin>>t>>c;
		a.push_back(str(t,c));
	}
	int cnt=0;
	while(!a.empty()){
		if(a.front().c==a.back().c){
			if(a.front().cnt>a.back().cnt){
				str fr=a.front();
				fr.cnt-=a.back().cnt;
				a.pop_back();
				a.pop_front();
				a.push_front(fr);
			}else if(a.front().cnt==a.back().cnt){
				if(a.size()==1) a.pop_back();
				else{
					a.pop_front();
					a.pop_back();
				}
			}else if(a.front().cnt<a.back().cnt){
				str fr=a.back();
				fr.cnt-=a.front().cnt;
				a.pop_back();
				a.pop_front();
				a.push_back(fr);
			}
		}else if(a.front().c!=a.back().c){
			if(a.front().cnt==a.back().cnt){
				cnt+=a.front().cnt;
				a.pop_front();
				a.pop_back(); 
			}else if(a.front().cnt>a.back().cnt){
				cnt+=a.back().cnt;
				int et=a.front().cnt-a.back().cnt;
				char cc=a.front().c;
				a.pop_back();
				a.pop_front();
				a.push_front(str(et,cc));
			}else if(a.front().cnt<a.back().cnt){
				cnt+=a.front().cnt;
				int et=a.back().cnt-a.front().cnt;
				char cc=a.back().c;
				a.pop_back();
				a.pop_front();
				a.push_back(str(et,cc));
			}
		}
	}
	cout<<cnt;
	
	return 0;
}
