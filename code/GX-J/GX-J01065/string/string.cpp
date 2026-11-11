#include <bits/stdc++.h>
using namespace std;

long long n,a[100005],cnt;
string s,b[100005];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){cout<<0;return 0;}
	if(n==2){ 
		while(n--){
			cin>>a[2-n]>>b[2-n];
		  }
		if(b[0]==b[1]){cout<<0;return 0;}
		else{cout<<min(a[1],a[0]);}}
	if(n<=10){
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			if(i!=1 && b[i-1]==b[i]){cnt++;}
			}
		if(cnt==n){cout<<0;return 0;}
		}
	for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			if(i!=1 && b[i-1]==b[i]){cnt++;}
			}
		if(cnt==n){cout<<0;return 0;}
	return 0;}	
