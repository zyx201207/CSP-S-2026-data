#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main () {
	
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	string s1="",s2="",s3="",s4="",s5="";
	int cnt1=0,cnt2=0;
	for(int i=1; i<=n; i++) {
		char c=i+'0';
		if(!s1.find(c))s1+=c;
		else {
			int k=s1.find(c);
			s1=s1.substr(0,k);
			s1+=c;
		}
	}
	if(s1.find('1'))cnt1++;
	if(s1.find('2'))cnt2++;
	for(int i=2; i<=n; i++) {
		char c=i+'0';
		if(!s2.find(c))s2+=c;
		else {
			int k=s2.find(c);
			s2=s2.substr(0,k);
			s2+=c;
		}
	}
	if(s2.find('1'))cnt1++;
	if(s2.find('2'))cnt2++;
	for(int i=3; i<=n; i++) {
		char c=i+'0';
		if(!s3.find(c))s3+=c;
		else {
			int k=s3.find(c);
			s3=s3.substr(0,k);
			s3+=c;
		}
	}
	if(s3.find('1'))cnt1++;
	if(s3.find('2'))cnt2++;
	for(int i=4; i<=n; i++) {
		char c=i+'0';
		if(!s4.find(c))s4+=c;
		else {
			int k=s4.find(c);
			s4=s4.substr(0,k);
			s4+=c;
		}
	}
	if(s4.find('1'))cnt1++;
	if(s4.find('2'))cnt2++;
	for(int i=5; i<=n; i++) {
		char c=i+'0';
		if(!s5.find(c))s5+=c;
		else {
			int k=s5.find(c);
			s5=s5.substr(0,k);
			s5+=c;
		}
	}
	if(s4.find('1'))cnt1++;
	if(s4.find('2'))cnt2++;
	if(m==1){
		cout<<cnt1;
		return 0;
	}else if(m==2){
		cout<<cnt1<<" "<<cnt2;
		return 0;
	} 

	return 0;
}
