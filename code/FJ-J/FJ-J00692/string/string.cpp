#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long n,i,a=0,sum=0;
string s,s1[N],s2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	while(n--){
		cin>>i>>s;
		while(i--) s1[a++]=s;
	}
	for(int i=0;i<a;i++) s2[i]=s1[a-i-1];
	for(int i=0;i<a;i++) if(s2[i]!=s1[i]) sum++;
	cout<<sum/2;
	return 0;
}
