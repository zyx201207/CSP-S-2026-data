//GZ-J00516 陈载烁阳 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string s,c;
long long n;
unsigned long long len,ans;
struct str{
	int num;
	string c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>c;
	for(int i=1;i<=x;i++)
		s+=c;
	} 
	len=s.size();
	for(int i=0,j=len-1;i<=len/2;i++,j--) if(s[i]!=s[j]) ans++;
	cout<<ans;
	
	
	
	
	
	
	return 0;
} 
