//GZ-J00283 赵宸泽 贵阳市观山湖区第一高级中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int l;
	char s;
}a[N];
int n;
string ns,s;
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].l>>a[i].s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i].l;j++)
			s+=a[i].s;
	for(int i=0;i<s.size();i++){
		int j=s.size()-i-1;
		if(s[i]==s[j]){
			s[i]=1;
			s[j]=1;
		}
	}		
	for(int i=0;i<s.size();i++)
		if(s[i]!='1' && s[i]<='z' && s[i]>='a') ns+=s[i];
	cout<<(ns.size())/2;
	return 0;
}
