#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
long long ans=0;
struct s{
	long long a;
	char c;
};
vector<s>str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		str.push_back({a,c});
	}
	vector<s>ss;
	ss.push_back(str[0]);
	int ssd=0;
	for(int i=1;i<n;i++){
		if(str[i].c==str[i-1].c)ss[ssd].a+=str[i].a;
		else {ss.push_back(str[i]);ssd++;}
	}
	int l=0,r=(int)(ss.size())-1;
	while(l<r){
		if(ss[l].c!=ss[r].c){
			if(ss[l].a>=ss[r].a){
				long long tmpa=ss[l].a;
				while(ss[r].a<=tmpa){
					if(ss[r].c!=ss[l].c)ans+=ss[r].a;
					ss[r].c=ss[l].c;
					tmpa-=ss[r--].a;
				}
				if(ss[r].c!=ss[l].c)ans+=tmpa;
				ss[r].a-=tmpa;
				r++;
			}
			else{
				ans+=ss[l].a;
				ss[r].a-=ss[l].a;
				ss.push_back(ss[l]);
				r++;
			}
		}
		else if(ss[l].a>ss[r].a){
			long long tmpa=ss[l].a;
				while(ss[r--].a<=tmpa){
					if(ss[r+1].c!=ss[l].c)ans+=ss[r+1].a;
					ss[r+1].c=ss[l].c;
					tmpa-=ss[r+1].a;
				}
				if(ss[r].c!=ss[l].c)ans+=tmpa;
				ss[r].a-=tmpa;
				r++;
		}else{
				ss[r].a-=ss[l].a;
				ss.push_back(ss[l]);
				r++;
			}
		l++;r--;
	}cout<<ans;
	return 0;
}
