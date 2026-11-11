#include<bits/stdc++.h>
using namespace std;
long long n,l,r,m,a,ans,sum,lsum,rsum;
char c;
struct node{
	long long aa;
	char cc;
};
vector<node>s,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s.push_back({0,0});
	d.push_back({0,0});
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		d.push_back({a,c});
	}
	m=sum/2;
	for(int i=1;i<=n;i++){
		a=d[i].aa,c=d[i].cc;
		if(m>0){
			if(a<=m)m-=a,s.push_back({a,c});
			else{
				long long b=a-m;a=a-b;
				s.push_back({a,c});
				s.push_back({b,c});
				m=0;
			}
		}else s.push_back({a,c});
	}
	m=sum/2;
	int l=1,r=s.size()-1,k=s.size()/2;
	while(lsum<=m&&rsum<=m){
		if(s[l].cc==s[r].cc){
			if(s[l].aa==s[r].aa){
				lsum+=s[l].aa;
				rsum+=s[r].aa;
				l++,r--;
			}
			else if(s[l].aa>s[r].aa){
				lsum+=s[r].aa,rsum+=s[r].aa;
				s[l].aa-=s[r].aa,r--;
			}
			else if(s[l].aa<s[r].aa){
				lsum+=s[l].aa;
				rsum+=s[l].aa;
				s[r].aa-=s[l].aa,l++;
			}
		}else{
			if(s[l].aa==s[r].aa){
				lsum+=s[l].aa;
				rsum+=s[r].aa;
				ans+=s[l].aa,l++,r--;
			}
			else if(s[l].aa>s[r].aa){
				lsum+=s[r].aa,rsum+=s[r].aa;
				ans+=s[r].aa;
				s[l].aa-=s[r].aa;
				r--;
			}else if(s[r].aa>s[l].aa){
				lsum+=s[l].aa;
				rsum+=s[l].aa;
				ans+=s[l].aa;
				s[r].aa-=s[l].aa;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
