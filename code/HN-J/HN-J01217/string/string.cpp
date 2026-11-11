#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,l,r;
string y;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>y;
		for(int j=0;j<a[i];j++){
			s+=y;
		}
	}
	long long c=s.size();
	if(c%2==1){
		l=c/2+1;
		r=c/2+1;
		for(int i=l,j=r;i>0,j<=s.size();i--,j++){
			if(s[i-1]!=s[j-1]){
				cnt++;
			}
		}
	}else{
		l=c/2;
		r=c/2+1;
		for(;l>0,r<=s.size();--l,++r){
			if(s[l-1]!=s[r-1]){
				cnt++;
			}
		}
	}cout<<cnt;
	return 0;
} 


		
