#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
string s[N];
string f(int x){
	string s;
	for(int i=0;x>0;i++){
		s+=x%2+'0';
		x/=2;
	}
	for(int i=0;i<s.size();i++){
		s[i]=s[s.size()-1-i];
	}
	return s;
}
int z(int x,int y){
	string s=f(x),t=f(y),q;
	int w;
	for(int i=0;i<min(s.size(),t.size());i++){
		if(s[i]==1&&t[i]==1){
			q+='1';
		}
	}
	int e=1;
	for(int i=q.size()-1;i>=0;i--){
		w+=(q[i]-'0')*e;
		e*=2;
	}
	return w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=2;i<=m;i++){
		ans=z(ans,a[i]);
	}
	cout<<ans;
	return 0;
}

