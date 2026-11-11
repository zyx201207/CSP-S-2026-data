#include<bits/stdc++.h>
using namespace std;
string s; 
inline bool check(string a){
	string b=a;
	reverse(a.begin(),a.end());
	return a==b;}
int n;
vector<pair<long long,char> > k;
inline void add(long long a,char b){while(a--)s+=b;}
long long ans(){
	long long cnt=0;
	for(int i=0,j=s.length()-1;i<=j;i++,j--)cnt+=(s[i]!=s[j]);
	return cnt;}
void smalldata(){
	if(n<2){
		cout<<0;
		exit(0);}
	if(n<3){
		long long a,b;
		char c,d;
		cin>>a>>c>>b>>d;
		if(c==d){
			cout<<0;
			exit(0);}
		cout<<min(a,b);
		exit(0);}}
void middata(){
	if(n>2000)return;
	k.resize(n);
	for(int i=0;i<n;i++)cin>>k[i].first>>k[i].second,add(k[i].first,k[i].second);
	if(check(s)){
		cout<<0;
		exit(0);}
	cout<<ans();
	exit(0);}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;
	smalldata();
	middata();
	long long cnt=0;
	k.resize(n);
	for(int i=0;i<n;i++)cin>>k[i].first>>k[i].second,cnt=max(cnt,k[i].first),s+=k[i].second;
	if(cnt<0){
		if(check(s)){
		cout<<0;
		return 0;}
		cout<<ans();
		return 0;}
	k.resize(n);
	cin>>k[0].first>>k[0].second;
	long long gcd=k[0].first;
	for(int i=0;i<n;i++)cin>>k[i].first>>k[i].second,gcd=__gcd(gcd,k[i].first);
	for(int i=0;i<n;i++)add(k[i].first/gcd,k[i].second);
	if(check(s)){
		cout<<0;
		exit(0);}
	cout<<ans()*gcd;
	return 0;}
