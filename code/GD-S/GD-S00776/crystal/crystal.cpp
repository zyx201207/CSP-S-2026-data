#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
ll n,m;
ll g[600086];//,p[600086];
map<ll,ll>be,en,le;
bool com(ll x,ll y){
	return le[x]>le[y];
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>g[i];
	sort(g+1,g+n+1);
	//ll ind=1,in=1,out=1,;
	
	ll bian=-(1<<30);
	vector<ll>v;
	for(int i=1;i<=n;i++){
		if(be.find(g[i])==be.end()){
			be[g[i]]=i;
			v.push_back(g[i]);
		}
		if(bian!=g[i]){
			en[bian]=i-1;
			bian=g[i];
		}
	}
	for(ll i : v){
		le[i]=en[i]-be[i]+1;
	}
	sort(v.begin(),v.end(),com);
	ll l=be[v[0]]-1,r=en[v[0]]+1;
	ll o=v[0];
	while(m>0&&(l>=1||r<=n)){
		if(l>=1&&r<=n){
			ll d1=o-g[l],d2=g[r]-o;
			if(d1<d2){
				m-=d1;
				if(m<0)break;
				l--;
			}else{
				m-=d2;
				if(m<0)break;
				r++;
			}
		}else if(l>=1){
			ll d1=o-g[l];
			m-=d1;
			if(m<0)break;
			l--;
		}else if(r<=n){
			ll d2 = o-g[r];
			m-=d2;
			if(m<0)break;
			r++;
		}
		
		
		
		/*ll d=(g[ind+1]-g[ind])*ind;
		m-=d;
		
		if(m<0)break;
		else g[ind]=g[ind+1];
		ind++;
		*/
	}
	cout<<r-l-1;
	/*if(ind==1){
		cout<<0;
		return 0;
	}
	
	if(m==0){
		while(g[ind]==g[ind+1]){
			ind++;
		}
		cout<<ind;
	}
	if(m<0)cout<<ind-1;
	*/
	
/*	while(ind<=n||in!=out){
		int a[2];
		for(int i=0;i<2;i++){
			if(out==in){
				a[i]=g[ind++];
				continue;
			}
			if(ind>n){
				a[i]=p[out++];
				continue;
			}
			a[i]=min(g[ind],p[out]);
			if(a[i]==g[ind])ind++;
			else out++;
		}
		ll d=a[0]-a[1];
		if(d<0)d=0-d;
		m-=d;
		if(m<0)break;
		p[in++]=d+a[0]+a[1];
	}
	*/
} 














/*#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll n,m,ans=0;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<ll>p(n+10);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)cout<<p[i];
	cout<<"\n";
	queue<ll>q;
	int t=1;
	sort(p.begin(),p.end());
	while(m>=0&&(t<=n||!q.empty())){
		int a[2];
		//求最小和 
		for(int i=0;i<2;i++){
			if(q.empty()){
				a[i]=p[t++];
				continue;
			}
			if(t>n){
				a[i]=q.front();
				q.pop();
				continue;
			}
			a[i]=min(q.front(),p[t]);
			if(a[i]==p[t])t++;
			else q.pop();
		}
		//求差 
		ll d=(a[0]<a[1]?a[1]-a[0]:a[0]-a[1]);
		m-=d;
		
		if(m<0)break;
		q.push(a[0]+a[1]+d);
		ans++;
		cout<<ans<<"\n";
	}
	cout<<ans;
} 
*/
