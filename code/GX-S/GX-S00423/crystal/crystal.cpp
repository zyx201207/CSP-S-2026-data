#include<bits/stdc++.h>
using namespace std;
//207;
int n=0;
long long m=0,t=1;
string w;
int p[207],f[207];
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	cin>>n>>w;
	if(w.size()>12){
		cout<<n;
		return 0;}
	if(w.size()==12&&(w[0]-'0')>1){
		cout<<n;
		return 0;}
	for(int i=0;i<int(w.size());i++){
		m=m+(w[int(w.size())-i-1]-'0')*t;
		t=t*10;}
	cout<<m<<endl;
	for(int i=1;i<=207;i++){
		p[i]=0,f[i]=0;}
	for(int i=1;i<=n;i++){
		int l=0;
		cin>>l;
		p[l+(207-5)/2]++;}
		f[1]=p[1];
	for(int i=2;i<=207;i++){
		int c=0,mm=m;
		for(int j=1;j<=i-1;j++){
			if(mm<=p[i-j]*j){
				c=c+mm/j;
				break;}
			else if(mm>p[i-j]*j){
				c=c+p[i-j];
				mm=mm-p[i-j]*j;}
			}
	//	if(c!=0) cout<<c<<" "<<i<<endl;	
		f[i]=p[i]+c;}
	int ans=0;
	for(int i=1;i<=207;i++){
		ans=max(ans,f[i]);}
		cout<<ans;
	return 0;
}
