#include <bits/stdc++.h>
using namespace std;
int c,t,n;
vector <long long> a[2000005];
long long d,x[2000005],sd=0,ds[2000005],ans;
bool p[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		ans=0,sd=1;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>x[i];
			for (int j=1;j<i;j++){
				if (abs(x[i]-x[j])<=d){
					a[i].push_back(j);
					a[j].push_back(i);
			    }
			}
		}
		queue <int> s;
		queue <bool> T;
		s.push(1),T.push(0);
		p[1]=true,ds[1]=0;
		while (s.size()){
			int g=s.front();
			s.pop();
			if (T.front()==1)  sd++;
			T.pop();
			bool w=true;
			for (int v : a[g]){
				if (p[v]){
					if (ds[v]==sd)  ans++;
					else  ds[v]=min(ds[v],sd);
				    continue; 
			    }
				s.push(v);
				p[v]=true; 
				ds[v]=sd;
				T.push(0);
				w=false;
			}
			if (!w)  T.pop(),T.push(1);
		}
		cout<<ans<<endl;
	}
}
