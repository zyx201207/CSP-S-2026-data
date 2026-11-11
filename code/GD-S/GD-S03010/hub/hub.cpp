#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
long long w[500050],v[500050];
struct way{
	int x;
	int y;
}a[500050];
bool cmp(way a,way b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	return a.x>b.x;
}
map<int,int> m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>w[i]>>v[i];
			m[abs(w[i]-v[i])]++;
			a[i].x=abs(w[i]-v[i]);
			a[i].y=m[abs(w[i]-v[i])];
		}
		sort(a+1,a+n,cmp);
		for(int i=1;i<n;i++){
			if(a[i].y>=k){
				cout<<a[i].x<<endl;
				break;
			}
		}
		continue;
	}
	return 0;
}
