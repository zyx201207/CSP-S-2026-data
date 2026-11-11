#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2*1e5+10;
string s,st;
ll n,a[N];
char c[N];
ll sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
//	cout<<"C数组:"<<endl;
//	for(ll i=1;i<=n;i++){
//		cout<<c[i]<<" ";
//	}
	bool b=1,k=1;
	for(ll i=1;i<n;i++){
		if(c[i]!=c[i+1]){
			b=0;
		}
		if(a[i]!=a[i+1]){
			k=0;
		}
	}
	if(b==1){//字母全是相同的 
		cout<<0;
		return 0;
	}
	if(k==1){//数字全是相同的 
		for(ll i=1;i<=n;i++){
			s+=c[i];
		}
	}
	else {
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
	}
//	cout<<s<<endl;
	for(ll i=s.size()-1;i>=0;i--){
		st+=s[i];
	}
//	cout<<st<<endl;
	if(s==st){
		cout<<0;
		return 0;
	}
//	cout<<s.size()<<" "<<st.size();
	for(ll i=0;i<s.size();i++){
		if(st[i]!=s[i])sum++;
	}
	if(k==1){
		cout<<sum*a[1]/2;
	}else{
		cout<<sum/2;
	}
	return 0;
}
