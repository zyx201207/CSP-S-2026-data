#include<bits/stdc++.h>
using namespace std;

string er(long long a){
	string s;
	while(a>0){
		s+=char(a%2+48);
		a/=2;
			
	}
	string s2;
	for(int i=s.length()-1;i>=0;i--){
		s2+=s[i]; 
	}
	return s2;
}
struct an{
	string s;
	long long a,l;
}a[20010];
string s[20010];
bool cmp(an a,an b){
	return a.l>b.l;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].a; 
		a[i].s=er(a[i].a);
		a[i].l=a[i].s.length();		
	}
	if(a[1].a==0&&m%2!=0){
		cout<<0;
		return 0;
	}
	if(a[1].a==0&&m==n){
		cout<<0;
		return 0;
	}
	if(a[1].a==0&&m%2==0){
		cout<<a[n-1].a;
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1].a;
		return 0;
	}
	
	cout<<a[m].a;
	
	
	
	return 0;
}
