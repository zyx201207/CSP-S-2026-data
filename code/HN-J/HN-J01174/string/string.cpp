#include<bits/stdc++.h>
using namespace std;
string s[200005],p,k;
int n;
long long ans;
void huiwen(string p){
	k=p;
	for(int i=0;i<p.size();i++){
		k[i]=p[p.size()-i-1];
	}
	for(int i=0;i<p.size()/2;i++){
		if(k[i]!=p[i]){
			ans++;
		}
	}
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[i]+=c; 
		}
		p+=s[i];
    }
	huiwen(p);
	cout<<ans;
	return 0;
} 
