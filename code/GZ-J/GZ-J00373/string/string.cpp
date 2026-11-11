//GZ-J00373 梁羽辰 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,a,m=0,l,r,ans;
string s;
char c;
long long down(long long x){
	if(x%2!=0){
		return (x-1)/2;
	}else return x/2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c; 
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	if(s.size()%2!=0){
		m=(s.size()+1)/2;
		l=m-1,r=m+1;	
	} else l=down(s.size()),r=l+2;
	for(long long i=0;i<s.size()/2;i++){
		if(s[l-i-1]!=s[r+i-1] || m==s[l] ||m==s[r]) ans++;
	}
	cout<<ans;
	return 0;
} 
