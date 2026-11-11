#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s,maxx=-10100101;
queue<long long>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(long long i=1;i<=n;i++){
	//	cout<<a[i]<<'\n';
//	}
	long long si=0;
	for(long long i=1;i<=n;){
//		cout<<q.size()<<' '<<s<<' '<<si<<'\n';
		if(s+(a[i]-a[i-1])*si<=m){
			maxx=max(maxx,(si+1));
			q.push(a[i]);
			
			s+=(a[i]-a[i-1])*si;
			si++;
			i++;
		}
		else{
			s-=(a[i-1]-q.front());
			q.pop();
			si--;
		}
	}
	cout<<maxx;
	return 0;
}
