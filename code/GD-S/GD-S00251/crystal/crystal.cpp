#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],ans=1,l=1,r,mid,check;
bool flag=1;
void dfs(int idx,long long sum,int cnt,long long maxx){
	if(check||idx>n)return;
	if(cnt==mid){
		for(int k=0;k<=m;k++){
			if(!((sum+k)%mid)&&maxx<=(sum+k)/mid){
				check=1;
				return;}}
		return;}
	dfs(idx+1,sum+a[idx],cnt+1,max(maxx,a[idx]));
	dfs(idx+1,sum,cnt,maxx);}
bool checkans(){
	check=0;
	dfs(1,0,0,LLONG_MIN);
	return check;}
void Away(){
	if(m>=(n-1)*n/2){
		cout<<n;
		exit(0);}
	while(l<=r){
		mid=(r-l)/2+l;
		if((1+mid)*mid/2<=m)ans=mid,l=mid+1;
		else r=mid-1;}
	cout<<ans+1;
	exit(0);}
void Bway(){
	long long gc=a[2]-a[1];
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=gc)return;
	if(m>=(n-1)*n/2*gc){
		cout<<n;
		exit(0);}
	while(l<=r){
		mid=(r-l)/2+l;
		if((1+mid)*mid*gc/2<=m)ans=mid,l=mid+1;
		else r=mid-1;}
	cout<<ans+1;
	exit(0);}
void makel(){
	long long pst=a[1],cnt=1;
	for(int i=2;i<=n;i++,ans=max(ans,cnt)){
		if(a[i]==pst)cnt++;
		else cnt=1,pst=a[i];}
	l=ans;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;}	
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag=0;}
	sort(a+1,a+n+1);
	if(flag)Away();
	Bway(); 
	makel();
	if(!m){
		cout<<ans;
		return 0;}
	while(l<=r){
		mid=(r-l)/2+l;
		if(checkans())ans=mid,l=mid+1;
		else r=mid-1;}
	cout<<ans;
	return 0;}
