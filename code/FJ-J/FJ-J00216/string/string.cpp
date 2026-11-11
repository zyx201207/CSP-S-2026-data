#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
string s;
long long a,ans,n;
char c;
struct node{
	int a,c;
	string s;
}st[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
//			cout<<i<<" "<<s[i]<<" "<<s[len-i-1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
