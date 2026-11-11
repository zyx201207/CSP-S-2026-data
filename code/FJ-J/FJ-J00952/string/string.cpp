#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans1=0,ans2=0,a[200005];
char b[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(long long j=0;j<a[i];j++){
			s=s+b[i];
		}
	}
	cnt=s.size();
	for(long long i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-i-1]){
			ans1+=1;
		}	
		if(s[cnt-i-1]!=s[i]){
			ans2+=1;
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}