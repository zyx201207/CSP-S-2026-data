#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans;
struct _{ll a;char c;};
vector<_> a;
void fit(){
	if(n==1) return;
	while(a[1].c==a[n].c){
		if(a[1].a==a[n].a){
			a.erase(a.begin()+1);
			a.pop_back();
			n-=2;
		}
		else{
			if(a[1].a>a[n].a){
				a[1].a-=a[n].a;
				a.pop_back();
				n--;
				break;
			}
			else{
				a[n].a-=a[1].a;
				a.erase(a.begin()+1);
				n--;
				break;
			}
		} 
	}
}
void solve(){
	cin>>n;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		if(i>1&&a[i].c==a[i-1].c){
			a[i-1].a+=a[i].a;
			a.erase(a.begin()+i);
			i--,n--;
		}
	}
	fit();
	if(n==1) { cout<<"0\n"; return; }
	if(n==2) { cout<<min(a[1].a,a[2].a)<<'\n'; return; }
	while(n>1){
		if(a[1].a<a[n].a) ans+=a[1].a,a[1].c=a[n].c;
		else ans+=a[n].a,a[n].c=a[1].c;
		fit();
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

/*
  11:50
  死咯
  留下最后的印记吧
  T1 100pts
  T2 64pts
  T3 40pts
  T4 0pts
  
  唉 
*/
