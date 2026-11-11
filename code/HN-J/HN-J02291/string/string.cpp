#include<bits/stdc++.h>
using namespace std; 
set<char> d;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005];
	char b[200005];
	long long q=0;
	cin>>n;
	for(long long  i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		q+=a[i];
		d.insert(b[i]);
	}
	if(d.size()==1){
		cout<<0<<endl;
		return 0; 
	}
	if(q%2!=0){
		long long  ba=0;
		long long  ed=a[1];
		for(long long  i=1;i<=n;i++){
			for(long long  j=ba;j<ed;j++){
				s+=b[i];
			}
			ba+=a[i];
			ed+=a[i+1];
		} 
		long long  qwe=s.size()-1,sum=0;
		for(long long  i=0;i<s.size();i++){
			if(i==s.size()/2){
				break;
			}
			if(s[i]!=s[qwe]){
				sum++;
			}
			qwe--;
		}
		cout<<sum<<endl;
		return 0;
	}
	if(q%2==0){
		long long  ba=0;
		long long  ed=a[1];
		for(long long  i=1;i<=n;i++){
			for(long long  j=ba;j<ed;j++){
				s+=b[i];
			}
			ba+=a[i];
			ed+=a[i+1];
		} 
		long long  qwe=s.size()-1,sum=0;
		for(long long  i=0;i<s.size();i++){
			if(i==s.size()/2){
				break;
			}
			if(s[i]!=s[qwe]){
				sum++;
			}
			qwe--;
		}
		if(s[s.size()/2]!=s[s.size()/2+1]){
			sum++;
		}
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}
