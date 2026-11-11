#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200010];
string s1,s2;
string t(int a){
	string s;
	int x=log2(a);
	for(int i=1;i<=x+1;i++){
		if(a%2==1){
			s+='1';
		}else{
			s+='0';
		}
		a/=2;
	}
	int l=s.size();
	for(int i=0;i<=l/2-1;i++){
		swap(s[i],s[l-1-i]);
	}
	return s;
}
int cmp(string a,string b){
	int ans=0,l=min(a.size(),b.size());
	for(int i=l-1;i>=0;i--){
		if(a[i]=='1'&&b[i]=='1'){
			ans+=pow(2,l-1-i);
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int a0;
		cin >> a0;
		a[i]=t(a0);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int d=cmp(a[i],a[j]);
			cnt=max(d,cnt);
			cout << a[i] << endl;
		}
	}
	cout << cnt;
	return 0;
}
