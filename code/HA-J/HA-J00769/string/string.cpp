#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,char> PII;
const int N=2e5+10;
long long n,a[N],sum,sum2,ans;
char c[N];
deque<PII> q,q2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		PII ca=q.front();
		int na=0;
		if(ca.second==c[i]){
			na=ca.first;
			q.pop_front();
		}
		q.push_back(make_pair(a[i]+na,c[i]));
		
	}
	sum2=sum;
	if(sum2%2){
		sum=(sum/2)+1;
		ll now=0;
		while(now<sum){
			now+=q.front().first;
			q2.push_back(q.front());
			q.pop_front();
		}
		if(now!=sum){
			PII ca=q2.back(),cb;
			q2.pop_back();
			cb=make_pair(now-sum,ca.second);
			if(now-sum) q.push_front(cb);
			if(ca.first+sum-now-1) q2.push_back(make_pair(ca.first+sum-now-1,ca.second));
		}else{
			PII ca=q2.back();
			q2.pop_back();
			if(ca.first-1) q2.push_back(make_pair(ca.first-1,ca.second));
		}
	}else{
		sum=(sum/2);
		ll now=0;
		while(now<=sum){
			now+=q.front().first;
			q2.push_back(q.front());
			q.pop_front();
		}
		PII ca=q2.back(),cb;
		q2.pop_back();
		cb=make_pair(now-sum,ca.second);
		if(now-sum) q.push_front(cb);
		if(ca.first+sum-now-1) q2.push_back(make_pair(ca.first+sum-now,ca.second));
	}
	ll l=1,r=sum2;
	if(sum2%2==0) l=0;
	/*while(q2.size()){
		cout<<q2.front().first<<" "<<q2.front().second<<"   ";
		q2.pop_front();
	}
	cout<<1<<"   ";
	while(q.size()){
		cout<<q.front().first<<" "<<q.front().second<<"   ";
		q.pop_front();
	}*/
	while(l<sum&&r>sum){
		PII aa=q2.front(),bb=q.back();
		if(aa.first>bb.first){
			l+=bb.first;
			r-=bb.first;
			if(aa.second!=bb.second){
				ans+=bb.first;
			}
			q2.pop_front();
			q.pop_back();
			q2.push_front(make_pair(aa.first-bb.first,aa.second));
		}else if(aa.first<bb.first){
			l+=aa.first;
			r-=aa.first;
			if(aa.second!=bb.second){
				ans+=aa.first;
			}
			q2.pop_front();
			q.pop_back();
			q.push_front(make_pair(bb.first-aa.first,bb.second));
		}else{
			l+=aa.first;
			r-=aa.first;
			if(aa.second!=bb.second){
				ans+=aa.first;
			}
			q2.pop_front();
			q.pop_back();
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

*/
