#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5*5;
const int M=1e5*3;
string a[N];
int cnt[M];
string change(int num){
	string result="",s="";
	while(num>0){
		result+=(char)(num%10+'0');
		num/=10;
	}
	for(int i=result.size()-1;i>=0;i--) s+=result[i];
	return s;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		string s="";
		
		for(int j=i;j<n;j++){
			string ch='#'+a[j]+' ';
			if((int)s.find(ch)==-1) s+=ch;
			else{
				s.erase((int)s.find(ch));
				s+=ch;
			}
		}
		for(int p=1;p<=m;p++){
			if((int)s.find('#'+change(p)+' ')!=-1) cnt[p]++;
		}
	}
	for(int p=1;p<=m;p++) cout<<cnt[p]<<' ';
	return 0;
}
