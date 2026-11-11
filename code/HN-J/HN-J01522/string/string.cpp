#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,sum,ans;
struct f{
	long long l,r;
	long long len;
	char x;
}a[N];
queue <f> q;
priority_queue <pair<long long,pair<long long,char> > > p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	sum=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].x;
		a[i].l=sum;
		sum+=a[i].len;
		a[i].r=sum-1;
	}
	sum--;
	for(int i=1;i<=n;i++){
		if(a[i].r<=sum/2) q.push(a[i]);
		else{
			if(a[i].l>(sum+1)/2) break;
			f k=a[i];
			k.r=sum/2;
			if(k.l>k.r) break;
			q.push(k);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].r<=sum/2) continue;
		else{
			if(a[i].l>(sum+1)/2){
				p.push({a[i].l,{a[i].r,a[i].x}});
				continue;
			}
			if(sum/2+1+(sum&1)>a[i].r) continue;
			p.push({sum/2+1+(sum&1),{a[i].r,a[i].x}});
		}
	}
	while(!q.empty()){
		f k=q.front();
		q.pop();
		long long len=k.r-k.l+1;
		while(len!=0){
			if(len>=p.top().second.first-p.top().first+1){
				len=len-(p.top().second.first-p.top().first+1);
				if(p.top().second.second!=k.x) ans+=(p.top().second.first-p.top().first+1);
				p.pop();
			}
			else{
				long long l=p.top().first,r=p.top().second.first;
				char X=p.top().second.second;
				p.pop();
				if(k.x!=X) ans+=len;
				p.push({l,{r-len,X}});
				len=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
