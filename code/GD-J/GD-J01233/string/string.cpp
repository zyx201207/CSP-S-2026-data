#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,char>> num,numr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	ll ai,sum=0,mid,mid2=0,cnt=0;
	char c;
	for(int i=0;i<n;i++){
		cin>>ai>>c;
		sum+=ai;
		num.push_back(make_pair(ai,c));
	}
	mid=sum/2;
	while(mid2<mid){
		ll a=num[num.size()-1].first;
		if(mid2+a<=mid){
			numr.push_back(num[num.size()-1]);
			num.erase(num.end()-1);
			mid2+=a;
			continue;
		}else{
			ll b=mid-mid2;
			num[num.size()-1].first-=b;
			numr.push_back(make_pair(b,num[num.size()-1].second));
			mid2+=b;
		}
	}
	//cout<<1<<endl;
	if(mid%2==1){
		if(num[num.size()-1].first==1){
			num.erase(num.end()-1);
		}else{
			num[num.size()-1].first-=1;
		}
	}
	while(!num.empty()){
		ll x=num[0].first;
		ll y=numr[0].first;
		char xc=num[0].second;
		char yc=numr[0].second;
		if(x>y){
			ll xy=y;
			num[0].first-=xy;
			numr.erase(numr.begin());
			if(xc!=yc)cnt+=xy;
		}else if(x<y){
			ll xy=x;
			numr[0].first-=xy;
			num.erase(num.begin());
			if(xc!=yc)cnt+=xy;
		}else{
			num.erase(num.begin());
			numr.erase(numr.begin());
			if(xc!=yc)cnt+=x;
		}
	}
	cout<<cnt;
	return 0;
}
