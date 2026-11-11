#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
long long n,cnt,ans;
struct Node{
	int a;
	char c;
}x[N];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
		for(int j=1;j<=x[i].a;j++){
			s+=x[i].c;
		}
		cnt+=x[i].a;
	}
	long long l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		l++;r--;
	}
	cout<<ans;
	return 0;
}
