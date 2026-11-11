#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define logn long
#define itn int
using namespace std;
long long n,a[200005],sum_len=0,ans=0;
string s[200005];
int main(){
	fre("string");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		sum_len+=a[i];
	}
	long long p=sum_len/2,sum=0,maxx=0;
	long long p_l=0,p_r=n-1,cnt_l=a[0],cnt_r=a[n-1];
	string cl=s[0],cr=s[n-1];
	while(sum<p){
		maxx=min(p-sum,min(cnt_l,cnt_r));
		if(cl!=cr)ans+=maxx;
		cnt_l-=maxx,cnt_r-=maxx,sum+=maxx;
		if(cnt_l<=0){
			cnt_l=min(p-sum,a[++p_l]);
			cl=s[p_l];
		}
		if(cnt_r<=0){
			cnt_r=min(p-sum,a[--p_r]);
			cr=s[p_r];
		}
	}
	cout<<ans;
	return 0;
}
