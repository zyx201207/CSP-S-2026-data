#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,cnt1;
string s,m;
char s1;
int f(string x){
	for(int i=x.size()-1;i>=0;i--){
		m+=x[i];
	}
	if(m==x)
		return 1;
	else return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
	}
	int l=s.size()-1;
	if(f(s)==1){
		cout<<0;
		return 0;
	}
	else {
		string q=s;
		for(int i=0;i<=l/2;i++){
			if(q[i]!=q[l-i]){
				q[i]=q[l-i];
				cnt++;
			}
		}
		string qq=s;
		for(int i=l/2+1;i<=l;i++){
			if(qq[i]!=qq[l-i]){
				qq[i]=qq[l-i];
				cnt1++;
			}
		}
	}
	cout<<min(cnt,cnt1);
	return 0;
}


