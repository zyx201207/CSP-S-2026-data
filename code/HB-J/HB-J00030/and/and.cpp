#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
string ejz(int x){
	string s;
	while(x>0){
		s+=x%2+'0';
		x/=2;
	}
	return s;
}
int he(int x,int y){
	string s1=ejz(x),s2=ejz(y);
	int h=0,a=1,b,l=min(s1.size(),s2.size());
	for(int i=0;i<l;i++){
		if(i!=0)a*=2;
		if(s1[i]==s2[i]){
			b=int(s1[i]-'0');
			if(i==0)h+=1*b;
			else {
				h+=b*a;
			}
		}
		
	}
	return h;
}
string he2(string s1,string s2){
	string s3;
	int l=min(s1.size(),s2.size());
	for(int i=0;i<l;i++){
		if(s1[i]==s2[i]&&s1[i]=='1'){
			s3+="1";
		}
		else s3+="0";
	}
	return s3;
}
int sz(string s){
	int x=s.size(),h=0,a=1,b;
	for(int i=0;i<x;i++){
		b=int(s[i]-'0');
		h+=a*b;
		a*=2;
	}
	return h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1)cout<<0;
	else if(m==2){
		int maxx=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				maxx=max(maxx,he(a[i],a[j]));
			}
		}
		cout<<maxx;
	}
	else if(m==n){
		string s=he2(ejz(a[0]),ejz(a[1]));
		for(int i=2;i<n;i++){
			s=he2(s,ejz(a[i]));
		}
		cout<<sz(s);
	}
	else if(m==n-1){
		int maxx=0;
		string sss;
		for(int i=0;i<n;i++){
			if(i==0)sss=he2(ejz(a[2]),ejz(a[1]));
			else if(i==1)sss=he2(ejz(a[0]),ejz(a[2]));
			else sss=he2(ejz(a[0]),ejz(a[1]));
			for(int j=0;j<n;j++){
				if(j!=i)sss=he2(sss,ejz(a[j]));
			}
			maxx=max(maxx,sz(sss));
		}
		cout<<maxx;
	}
	else cout<<1;
	return 0;
}
