#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005];
char al[200005],bl[200005];
string s;
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long mxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>al[i];
		b[n-i+1]=a[i];
		bl[n-i+1]=al[i];
		mxa=mxa+(long long)a[i];
	}
	if(mxa<=20000007){
		s.push_back('0');
		for(int i=1;i<=n;i++){
			while(a[i]--) s.push_back(al[i]);
		}
		for(int i=1;i<s.size();i++){
			if(s[i]!=s[s.size()-i]) ans++;
			s[i]=s[s.size()-i];
		}
		cout<<ans;
		return 0;
	}
	/*
	for(int i=1;i<=n;i++){
		b[i]=b[i]+b[i-1];
		a[i]=a[i]+a[i-1];
	}
	long long ans1=0,ans2=0;
	long long p1=1,p2=1;
	int ti=lower_bound(a+1,a+1+n,mxa/2)-a;
	int ti2=lower_bound(b+1,b+1+n,mxa/2)-b;
	while(p1<=ti||p2<=ti2){
		if(al[p1]==bl[p2]){
			if(a[p1]<b[p2]) p1++;
			else if(a[p1]>b[p2]) p2++;
			else p1++,p2++;
		}else{
			ans1+=min(min(a[p1],mxa/2)-a[p1-1],min(b[p2],mxa/2)-b[p2-1]);
			if(a[p1]<b[p2]) p1++;
			else if(a[p1]>b[p2]) p2++;
			else p1++,p2++;
		}
	}
	cout<<ans1;
	if(mxa*n<=200004){
		
		return 0;
	}*/
	for(int i=1;i<=n;i++){
		b[i]=b[i]+b[i-1];
	}
	long long ans1=0,ans2=0;
	long long p1=0,p2=0;
	for(int i=1;i<=n/2;i++){
		p1+=a[i];
		p2=lower_bound(b+1,b+1+n,p1)-b;
		if(b[p2]>p1) p2--;
		if(al[i]==bl[p2]) continue;
		if(b[p2]-b[p2-1]>a[i]){
			
		}
		ans1+=a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i]-b[i-1];
		a[i]=a[i]+a[i-1];
	}
	p1=0,p2=0;
	for(int i=1;i<=n/2;i++){
		p1+=b[i];
		p2=lower_bound(a+1,a+1+n,p1)-a;
		if(a[p2]>p1) p2--;
		if(bl[i]==al[p2]) continue;//
		ans2+=b[i];
	}
	cout<<min(ans1,ans2);
	return 0;
}
