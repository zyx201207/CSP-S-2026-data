#include<bits/stdc++.h>
using namespace std;
string a[200005];
vector<string> b;
int ans=0;
string f(int a){
	string s="";
	for(int i=1;i<=31;i++){
		char c=a%2+'0';
		s+=c;
		a/=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=f(x);
	}
	int cnt=0,s;
	for(s=30;s>=0;s--){
		for(int i=1;i<=n;i++){
			if(a[i][s]=='1')cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(a[i][s]=='1')b.push_back(a[i]);
			}
			cnt=0;
			break;
		}
		cnt=0;
	}
	while(s>=0){
		ans*=2;
		for(string c:b){
			if(c[s]=='1')cnt++;
		}
		if(cnt>=m){
			int size=b.size();
			for(int i=0;i<size;i++){
				if(b[i][s]=='0')b.erase(b.begin()+i);
			}
			ans++;
		}
		cnt=0;
		s--;
	}
	cout<<ans;
	return 0;
}
