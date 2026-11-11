#include<bits/stdc++.h>
using namespace std;
int n1,n2,a[205],b[205];
string s1,s2;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	a['A']=a['B']=a['C']=1;
	a['D']=a['F']=2;
	b['A']=1;b['B']=2;b['C']=3;b['D']=5;b['F']=6;
	if(n1==n2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0')cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	} 
	if(a[s1[2]]==a[s2[2]])cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(b[s1[2]]-b[s2[2]])==1)cout<<1;
	else cout<<0;
}
