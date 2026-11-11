#include <bits/stdc++.h>
using namespace std;
long long x[2000005],v[2000005],n,d,mn=1e9,mn2=0,mn3=0,mn4=0;
vector <long long> t,r,e,f;
void d2(long long a,long long b){
	
	if (a==b){
		long long u=e.size();
		if (u!=0){
		e.push_back(x[a]);
		for (long long i=1;i<e.size();i++) {
			if (e[i]-e[i-1]>d) {
				e.pop_back();
				return ;
			}
		}
		if (mn!=mn3) mn2=0;
		if (u==mn) mn2++,mn3=u;
		mn=min(mn,u);
		
		e.pop_back();
	}	
		if (e[0]==x[b-1] and e.size()==1 ) {
			if (mn2==1) mn4++;
		}
		return ;
	}
	
	e.push_back(x[a]);
	d2(a+1,b);
	e.pop_back();
	d2(a+1,b);
}
void dfs(long long q){
	
	if (q==2){
		if (t[0]+2<t[1]) {
			
			d2(t[0],t[1]);
			
		}
		
		return ;
	}
	for (long long i=1;i<=n;i++){
		if (v[i]!=1){
		v[i]=1;
		t.push_back(i);
		
		dfs(q+1);
		t.pop_back();
		v[i]=0;
		
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (long long i=1;i<=n;i++){
			v[i]=0;
		}
		
		for (long long i=1;i<=n;i++){
			cin>>x[i];
		}
		mn=1e9,mn2=0,mn3=0,mn4=0;
		dfs(0);
		cout<<mn4<<endl;
		
		
	}
	return 0;
}
