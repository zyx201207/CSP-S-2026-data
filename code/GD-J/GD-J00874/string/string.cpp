#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],mid,l,r,len=0,ans=0;
char x;
string s={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>x;
		s+=x,len+=a[i];
//		cout<<a[i];
	}
//	cout<<' '<<len<<' ';
	mid=len/2;
	if(len==2){
		cout<<(s[0]==s[1])?0:1;
		return 0;
	}
	if(len<=1){
		cout<<0;
		return 0;
	}
	if(mid%2==0) l=mid-1,r=mid+1;
	else l=mid-1,r=mid;
	while(l>=0&&r<len){
		if(s[l]!=s[r]) ans++;
		l--,r++;
	}
	cout<<ans;
	return 0;
}
