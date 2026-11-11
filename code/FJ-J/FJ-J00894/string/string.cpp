#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
string s1="",s2="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s1+=a;
		}
	}
	s2=s1;
	reverse(s1.begin(),s1.end());
	long long sum=0;
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s2[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
