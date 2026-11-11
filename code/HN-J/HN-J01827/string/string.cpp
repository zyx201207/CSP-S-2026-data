#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0ll,len=0ll;
	vector<pair<long long,char> > str;
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long s;
		char c;
		cin>>s>>c;
		str.push_back({s,c});
		len+=s;
	}
	long long l=0,r=len-1;
	long long a=0,b=str.size()-1;
	while(l<=r){
		if(str[0+a].first==0ll){
			//str.erase(str.begin());
			a++;
		}
		if(str[0+b].first==0ll){
			//str.erase(str.end()-1);
			b--;
		}
		long long mn=min(str[0+a].first,str[0+b].first);
		if(str[0+a].second!=str[0+b].second){
			ans+=mn;
			l+=mn;
			r-=mn;
			str[0+a].first-=mn;
			str[0+b].first-=mn;
		}
		else if(str[0+a].second==str[0+b].second){
			l+=mn;
			r-=mn;
			str[0+a].first-=mn;
			str[0+b].first-=mn;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
