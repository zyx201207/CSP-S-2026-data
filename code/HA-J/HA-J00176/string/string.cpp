#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans;
struct Node{
	long long a;
	char c;
};
vector<Node> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		Node b;
		cin>>b.a>>b.c;
		s.push_back(b);
	}
	while(s.size()>1){
		if(s[0].c!=s[s.size()-1].c){
			if(s[0].a>=s[s.size()-1].a){
				ans+=s[s.size()-1].a;
				s[0].a-=s[s.size()-1].a;
				s.erase(s.end()-1,s.end());
			}
			else{
				ans+=s[0].a;
				s[s.size()-1].a-=s[0].a;
				s.erase(s.begin(),s.begin()+1);
			}
		}
		else{
			if(s[0].a>=s[s.size()-1].a){
				s[0].a-=s[s.size()-1].a;
				s.erase(s.end()-1,s.end());
			}
			else{
				s[s.size()-1].a-=s[0].a;
				s.erase(s.begin(),s.begin()+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
