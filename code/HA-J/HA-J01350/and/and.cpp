#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	string s;
	int num;
}sk[N];
bool cmp(node a,node b){
	return a.s>b.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		string a;
		sk[i].num=x;
		while(x){
			a.push_back(x%2+'0');
			x>>=1;
		}
		reverse(a.begin(),a.end());
		while(a.size()<31)a='0'+a;
		sk[i].s=a;
	}
	sort(sk+1,sk+n+1,cmp);
	int res=sk[1].num;
	for(int i=1;i<=m;i++)res&=sk[i].num;
	cout<<res;
	return 0;
}

