#include<bits/stdc++.h>
using namespace std;
struct stu{
	string e;
	int tmp=0;	
}a[20000];
bool cmp(stu a,stu b){
	if(a.tmp!=b.tmp)return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;
		int t;
		cin>>t;
		a[i]=t;
		while(t>0){
		char f;
		if(t%2==1)f='1';
		else f='0';
		s+=f;
		t/=2;
	}
	for(int j=0;j<s.size();j++)a[i].e[j]=s[s.size()-j-1];
	for(int j=0;j<s.szie();j++){
		if(a[i].e[j]=='1')a[i].tmp++;
	}	
}
	sort(a,a+n,cmp);
}
