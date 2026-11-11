#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=2e6+10;
ll a[N];
ll n,d;
int find1(int x,int R){
	int l=x,r=R;
	int best=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]-a[x]<=d){
			best=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return best;
}
int find2(int x,int L){
	int l=L,r=x;
	int best=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[x]-a[mid]<=d){
			best=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return best;
}
bool check(int l,int r){
	int i=l;
	vector<int>ansl;
	vector<int>ansr;
	while(i<=r){
		ansl.push_back(i);
		i=find1(i,r);
	}
	if(i!=r){
		ansl.push_back(r);
	}
	i=r;
	while(i>=l){
		ansr.push_back(i);
		i=find2(i,l);
	}
	if(i!=l){
		ansr.push_back(l);
	}
	if(ansl.size()==ansr.size()){
		int L=0,R=ansl.size();
		while(L<=R){
			if(ansl[L]!=ansr[R]){
				return 1;
			}
		}
	}
	return 0;
}
void solve1(){
	ll tot=0;
	for(int len=4;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			tot+=check(l,r);
		}
	}
	cout<<tot;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		solve1();
	}
	return 0;
}
