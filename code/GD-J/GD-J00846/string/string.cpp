#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{int num;char c;};
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin >> n;
	vector<node> v(n+1);
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin >> num >> c;
		v[i].num=num;
		v[i].c=c;
		sum+=num;
	}
	int hf=sum/2;
	int ll=0,rr=0;
	vector<node> l,r;
	for(int i=1;i<=n;i++){
		int num=v[i].num;
		char c=v[i].c;
		if(ll+num<=hf){
			l.push_back({num,c});
			ll+=num;
		}
		else{
			l.push_back({hf-ll,c});
			ll=hf;
			
		}
		if(ll==hf)break;
	}
	for(int i=n;i>=1;i--){
		int num=v[i].num;
		char c=v[i].c;
		if(rr+num<=hf){
			r.push_back({num,c});
			rr+=num;
		}
		else{
			r.push_back({hf-rr,c});
			rr=hf;
			
		}
		if(rr==hf)break;
	}
	//for(int i=0;i<r.size();i++)cout << r[i].num << " ";
	int id=0;
	for(int i=0;i<l.size();i++){
		while(l[i].num>0){
			if(l[i].num-r[id].num>=0){
				l[i].num-=r[id].num;
				if(l[i].c!=r[id].c)ans+=r[id].num;
				id++;
			}
			else{
				r[id].num-=l[i].num;
				if(l[i].c!=r[id].c)ans+=l[i].num;
				l[i].num=0;
			}
		}
	}
	cout << ans;
	return 0;
} 
