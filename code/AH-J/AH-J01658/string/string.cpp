#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],l,cnt1,cnt2;
char ch[200010];
string s,s1,s2;
bool pd(string x){
	string x1,x2;
	x1=x;
	x2=x;
	for(int i=0;i<(l/2);i++){
		swap(x2[i],x2[l-i-1]);
	}
	if(x1==x2)return 1;
    else return 0; 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>ch[i];
		for(int j=0;j<a[i];j++){
			s+=ch[i];
		}
	}
	l=s.size();
	s1=s;
	s2=s;
	for(int i=0;i<(l/2);i++){
		if(pd(s))break;
		else{
			if(s1[i]!=s1[l-i-1]){
				s1[l-i-1]=s1[i];
				cnt1++;
				}
		}
	}
	cout<<cnt1;
	return 0;
	}
