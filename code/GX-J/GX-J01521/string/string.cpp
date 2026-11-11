#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=0;
char c;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	long long h=s.size();
	for(long long i=0;i<h/2;i++) s1=s1+s[i];
	for(long long i=h-h/2;i<=h;i++) s2=s2+s[i];
	if(s1==s2){
		cout<<sum;
		return 0;
	}
	long long h1=s1.size();
	for(long long i=0;i<h1;i++) if(s1[i]!=s2[i]) sum++;
	cout<<sum;
	return 0;
}
