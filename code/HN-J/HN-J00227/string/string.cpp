#include<bits/stdc++.h>
using namespace std;
struct A{
	long long s,e,l;
	char c;
}s[200010];
long long n,len=0,ans=0,m=0,add;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=2000){
		string x;
		for(int i=1;i<=n;i++){
			long long a;
			char c;
			cin>>a>>c;
			for(int j=1;j<=a;j++) x[len+j]=c;
			len+=a;
		}
		for(int i=1;i<=(len+1)/2;i++){
			if(x[i]!=x[len-i+1]) ans++;
		}
		cout<<ans;
		return 0;
	}
	
	
	int fl=1;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		if(a>500) fl=0;
		s[i].s=len+1;
		len+=a;
		s[i].e=len;
		s[i].c=c; 
		s[i].l=a;
		m+=a;
	}
	if(fl==1){
		string x;
		for(int i=1;i<=n;i++){
			for(int j=s[i].s;j<=s[i].e;j++) x[j]=s[i].c;
		}
		for(int i=1;i<=(len+1)/2;i++){
			if(x[i]!=x[len-i+1]) ans++;
		}
		cout<<ans;
		return 0;
	}
	
	
	
	for(int i=1;i<n;i++){
		if(s[i].c==s[i+1].c){
			s[i].l+=s[i+1].l;
			s[i].e=s[i+1].e;
			s[i+1].l=0;
			add++;
		}
	}
	n-=add;
	m/=2;
	int l=0,o=1;
	for(int i=1;i<=n;i++){
		if(s[i].l==0) continue;
		if(s[i].s<=m&&s[i].e>=m){
			l=o;
			o++;
			break;
		}
	}
	if(l==0) l=n/2;
	for(int i=1;i<=l;i++){
		if(i==n-i+1) continue;
		if(s[i].c==s[n-i+1].c){
			if(s[i].l>s[n-i+1].l){
				s[i].l-=s[n-i+1].l;
				s[n-i+1].l=0;
			}
			else if(s[i].l<s[n-i+1].l){
				s[n-i+1].l-=s[i].l;
				s[i].l=0;
			}
			else{
				s[n-i+1].l=0;
				s[i].l=0;
			}
		}
	}
	for(int i=1;i<=n;i++) ans+=s[i].l;
	cout<<ans/2<<" "<<l<<" "<<endl;
	for(int i=1;i<=n;i++) cout<<i<<" "<<s[i].l<<endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
