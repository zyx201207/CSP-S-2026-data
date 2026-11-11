#include<bits/stdc++.h>
using namespace std;
size_t n,a,ans,min_;
char c;
vector<pair<size_t,char>>s;
void f(size_t i){
	if(s[i].first<=min_){
		s.erase(s.begin()+i);
		return;
	}
	s[i].first-=min_;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(size_t i=0;i<n;i++){
		cin>>a>>c;
		s.push_back({a,c});
	}
	while(s.size()>1){
		min_=std::min(s[0].first,s[s.size()-1].first);
		if(s[0].second!=s[s.size()-1].second){
			ans+=min_;
		}
		f(s.size()-1);
		f(0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
