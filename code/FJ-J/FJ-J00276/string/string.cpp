#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long l;
	char ch;
};
int ll,rr;
long long ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<node> p(n+5);
	for(int i=1;i<=n;i++){
		cin>>p[i].l>>p[i].ch;
	}
	ll=1,rr=n;
	while(ll<=rr){
		if(p[ll].ch!=p[rr].ch){
			if(p[ll].l>p[rr].l){
				ans+=p[rr].l;
				p[ll].l-=p[rr].l;
				p[rr].l=0;
				rr--;
			}
			else if(p[ll].l<p[rr].l){
				ans+=p[ll].l;
				p[rr].l-=p[ll].l;
				p[ll].l=0;
				ll++;
			}
			else{
				ans+=p[ll].l;
				p[ll].l=p[rr].l=0;
				ll++;rr--;
			}
		}
		else{
			if(p[ll].l>p[rr].l){
				p[ll].l-=p[rr].l;
				p[rr].l=0;
				rr--;
			}
			else if(p[ll].l<p[rr].l){
				p[rr].l-=p[ll].l;
				p[ll].l=0;
				ll++;
			}
			else{
				p[rr].l=p[ll].l=0;
				ll++;rr--;
			}
		}
	}
	cout<<ans;
	return 0;
}

