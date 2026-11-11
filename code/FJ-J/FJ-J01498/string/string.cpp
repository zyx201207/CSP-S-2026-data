#include<iostream>
using namespace std;
const int N=2e5+5;
struct Node{
	long long x;
	char c;
}node;
int n;
Node arr[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i].x);
		cin>>arr[i].c;
		for(int j=1;j<=arr[i].x;j++){
			s+=arr[i].c;
		}
	}
//	cout<<s;
	long long ans=0;
	long long slen=s.size();
	for(long long i=0;i<slen/2;i++){
		if(s[i]!=s[slen-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
