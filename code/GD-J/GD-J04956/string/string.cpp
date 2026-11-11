#include<iostream>
#include<string>
using namespace std;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char d;
		cin>>a>>d;
		while(a--){
			s+=d;
		}
	}
	long long l=0,r=s.size()-1;
	long long cnt=0;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;r--;
	}
	cout<<cnt;
	return 0;
}
