#include<bits/stdc++.h>
using namespace std;

//#define int long long

const long long N=200005;
long long a[N],n,ans=0,sum=0;
char c[N];
void bl()
{
	string s="";
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	//cout<<s<<endl;
	for(long long i=0;i*2<s.size();i++){
		if(s[i]!=s[s.size()-1-i]) {
			//cout<<s[i]<<endl;
			ans++;
		}
	}
	return ;
}
/*void work()
{
	long long mid=sum/2,t=0,f;
	if(sum%2==1) mid++;
	for(long long i=1;i<=n;i++){
		if(t+a[i]>=mid){
			f=i;
			break;
		}
		else t+=a[i]; 
	}
	t=0;
	//cout<<f<<"\n";
	for(long long i=1;i<=f;i++){
		if(i<f){
			t+=a[i];
			char now_c=c[i];
			long long ll=sum-t,rr=sum-t+a[i];
			ans+=(ll-rr-check(ll,rr,now_c));
		}
	}
	return ;
}
long long check(int ll,int rr,char now_ch)
{
	
}*/
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(long long i=1;i<=n;i++) sum+=a[i];
	bl();
	cout<<ans;
	return 0;
}
/*
97 a
122 z
aaabbbhckfhqbbaaa
abhcfpha
aanklaba


*/
