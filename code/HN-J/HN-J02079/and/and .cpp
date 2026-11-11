#include<bits/stdc++.h>
using namespace std;
struct node{
	int k,t;
}a[200005];
int n,m;
bool cmp(node x,node y){
	return x.t>y.t;
}
int f(int n){
	vector<int> v;
	while(n){
		v.push_back(n%2);
		n/=2;
	}
	int s;
	for(int i=0;i<v.size();i++){
		s+=v[i];
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		a[i].t=f(a[i].k);
	}
	sort(a+1,a+n+1,cmp);
	int s=a[1].k;
	for(int i=2;i<=m;i++){
		s&=a[i].k;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
