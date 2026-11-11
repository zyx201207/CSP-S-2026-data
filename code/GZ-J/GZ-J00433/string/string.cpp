//GZ-J00433 贵阳市南明区华麟学校 张其浩
#include<bits/stdc++.h>
using namespace std;
string cz(long long k,char l){
	string h;
	for(int i=1;i<=k;i++)h+=l;
	return h;
}
long long n,a[110000],cnt1=1,cnt2=1,cnt3=0;
char c[110000];
string s1,s2,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;	
	long long len=0;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1])cnt1++;
		if(a[i]==a[i+1])cnt2++;
		len+=a[i];
	}
	if(cnt1==n){
		cout<<0;
		return 0;
	}
	if(cnt2==n){
		for(int i=1;i<=n;i++)s1+=c[i];
		len = s1.size();
		for(int i=len-1;i>len/2;i--)s2+=s1[i];
		len/=2;
		for(int i=0;i<len;i++){
			if(s2[i]!=s1[i])cnt3++;
		}
		cout<<cnt3*a[1];
		return 0;
	}
	long long x = len/2;
	for(int i=1;i<=n;i++)s+=cz(a[i],c[i]);
	for(int i=0;i<x;i++)s1+=s[i];
	for(int i=len-1;i>x;i--)s2+=s[i];
	for(int i=0;i<len;i++){
		if(s1[i]!=s2[i])cnt3++;
	}
	cout<<cnt3;
	return 0;
}
