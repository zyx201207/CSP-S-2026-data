#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a!=b) return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n),p(m);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<m;i++){
		p[i]=v[i];
	}
	int maxx=p[0];
	for(int i=1;i<m;i++){
		maxx=maxx&p[i];
	}
	cout<<maxx;
	return 0;
}
