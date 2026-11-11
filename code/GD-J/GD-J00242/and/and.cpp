#include<bits/stdc++.h>
using namespace std;
int n,m,MAX=INT_MIN;
int countone(int a){
	bitset<32> b=a;
	return b.count();}
vector<pair<int,int> > k;
bool cmp1(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second)return a.first>b.first;
	return a.second>b.second;}
bool cmp2(pair<int,int> a,pair<int,int> b){return a.first>b.first;}
int ans1(){
	sort(k.begin()+1,k.end(),cmp1);
	int ans=k[1].first;
	for(int i=1;i<=m;i++)ans&=k[i].first;
	return ans;}
int ans2(){
	sort(k.begin()+1,k.end(),cmp2);
	int ans=k[1].first;
	for(int i=1;i<=m;i++)ans&=k[i].first;
	return ans;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	k.resize(n+1);
	for(int i=1;i<=n;i++)cin>>k[i].first,MAX=max(MAX,k[i].first),k[i].second=countone(k[i].first);
	if(m==1){
		cout<<MAX;
		return 0;}
	cout<<max(ans1(),ans2());
	return 0;}
