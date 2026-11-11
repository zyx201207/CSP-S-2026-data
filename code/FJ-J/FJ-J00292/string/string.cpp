#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,h=0,ans=0;
struct N{
	ll k=0;
	char c=0;
};
vector<N> a,x;
deque<N> y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//system("diff a.in b.in");
	cin>>n;
	N p;
	for(ll i=1;i<=n;i++){
		cin>>p.k>>p.c;
		if(a.size()&&a[a.size()-1].c==p.c)a[a.size()-1].k+=p.k;
		else a.push_back(p);
		h+=p.k;
	}
	h=h/2;
	//cout<<h;
	ll id=0;
	for(ll i=0;i<h&&id<a.size();){
		if(a[id].k+i<=h)x.push_back(a[id]),i+=a[id].k,id++;
		else{
			a[id].k-=(h-i);
			if(h%2)a[id].k-=1;
			p.k=h-i,p.c=a[id].c;
			if(a[id].k==0)id++;
			x.push_back(p);
			break;
		}
	}
	for(ll i=0;i<h&&id<a.size();){
		y.push_front(a[id]),i+=a[id].k,id++;
	}
	int xx=0,yy=0;
	for(int i=0;i<x.size();i++)xx+=x[i].k;
	for(int i=0;i<y.size();i++)yy+=y[i].k;
	ll l=0,r=0;
	while(l<x.size()&&r<y.size()){
		if(x[l].k==y[r].k){
			if(x[l].c==y[r].c){
				l++,r++;
				continue;
			}
			else {
				ans+=x[l].k;
				l++,r++;
				continue;
			}
		}
		else if(x[l].k>y[r].k){
			if(x[l].c!=y[r].c){
				ans+=y[r].k,x[l].k-=y[r].k,r++;
			}
			else{
				x[l].k-=y[r].k,r++;
			}
		}
		else{
			if(x[l].c!=y[r].c){
				ans+=x[l].k,y[r].k-=x[l].k,l++;
			}
			else{
				y[r].k-=x[l].k,l++;
			}
		}
	}
	cout<<ans;
	return 0;
}


