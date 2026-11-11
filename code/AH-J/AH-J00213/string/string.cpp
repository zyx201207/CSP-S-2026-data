#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,s=0;
char c;
struct node{
	__int128 n;
	char c;
};
vector<node> a,h,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>c;
		if(!a.empty()&&a.back().c==c) a.back().n+=k;
		else a.push_back({k,c});
	}
	for(int i=0,j=a.size()-1;i<j;){
		if(a[i].n>a[j].n){
			h.push_back({a[j].n,a[i].c});
			t.push_back(a[j]);
			a[i].n-=a[j].n;
			j--;
		} else if(a[i].n<a[j].n){
			h.push_back(a[i]);
			t.push_back({a[i].n,a[j].c});
			a[j].n-=a[i].n;
			i++;
		} else{
			h.push_back(a[i]);
			t.push_back(a[j]);
			i++;
			j--;
		}
	}
	for(int i=0;i<h.size();i++) if(h[i].c!=t[i].c) s+=h[i].n;
	cout<<s;
	return 0;
}
