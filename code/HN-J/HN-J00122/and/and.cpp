#include<iostream>
#include<algorithm>
using namespace std;
bool cmb(long long a,long long b){
	return a>b;
}
string ss(string s1,string s2){
	string c;
	for (int i=0;i<s2.size();i++){
		if(s1[i]=='1'&&s2[i]=='1'){
			c=c+'1';
		}else{
			c=c+'0';
		} 
	}
	return c;
}
long long as(string s1){
	long long sum=0,a=1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='1'){
			sum=sum+a;
		}
		a=a*2;
	}
	return sum;
}
struct aa{
	string str;
}b[200000];
bool cmb2(aa c,aa d){
	int cnt1=0,cnt=0;
	for(int i=0;i<c.str.size();i++){
		if(c.str[i]=='1')cnt++;
	} 
	for(int i=0;i<d.str.size();i++){
		if(d.str[i]=='1')cnt1++;
	} 
	return cnt>cnt1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[200000];
	int n,r;
	cin>>n>>r;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+5,cmb);
	for(int i=0;i<n;i++){
		int ai=a[i];
		while(ai){
			b[i].str=b[i].str+char('0'+ai%2);
			ai=ai/2;
		}
	}
	int x[2],l=0;
	sort(b,b+n,cmb2);
	string str=b[0].str;
	
	for(int i=1;i<r;i++){
		str=ss(str,b[i].str);
	}
	cout<<as(str); 
	return 0;
}
