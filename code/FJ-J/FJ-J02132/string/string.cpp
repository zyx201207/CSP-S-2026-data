#include<bits/stdc++.h>
using namespace std;
struct st{
	long long su;
	char b;
};
st s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long ans=0,g=0;
	cin>>n;
	long long ll=0;
	for(long long i=1;i<=n;i++){
		cin>>s[i].su >>s[i].b ;
	}
	long long l=1,r=n;
	while(1)
	{
		if(l==r || l>r)break;
		if(s[l].su >s[r].su && s[l].b !=s[r].b ){
			s[l].su-=s[r].su;
			ans+=s[r].su;
			s[r].su=0;
			r--;
		}
		if(s[l].su >s[r].su && s[l].b ==s[r].b ){
			s[l].su-=s[r].su;
			s[r].su=0;
			r--;
		}
		if(s[l].su <s[r].su && s[l].b !=s[r].b ){
			s[r].su-=s[l].su;
			ans+=s[l].su;
			s[l].su=0;
			l++;
		}
		if(s[l].su <s[r].su && s[l].b ==s[r].b ){
			s[r].su-=s[l].su;
			s[l].su=0;
			l++;
		}
		if(s[l].su==s[r].su && s[l].b != s[r].b ){
			ans+=s[l].su;
			s[l].su=0;
			s[r].su=0;
			l++;
			r--;
		}
		if(s[l].su==s[r].su && s[l].b == s[r].b ){
			s[l].su=0;
			s[r].su=0;
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
