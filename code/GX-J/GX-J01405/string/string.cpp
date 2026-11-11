#include<bits/stdc++.h>
using namespace std;

string r(string a){
	string b;
	for(int i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	return b;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int ans=0;
	if(s==r(s)){
		cout<<0;
	}else{
		int a=s.size()/2;
		string c=s.substr(0,0+a);
		string d;
		if(s.size()%2==0){
			d=s.substr(a,a);
		}else{
			d=r(s.substr(a+1,a));
		}
		for(int i=0;i<=a-1;i++){
			if(c[i]!=d[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
