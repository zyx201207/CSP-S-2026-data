#include<bits/stdc++.h>
using namespace std;
int a[200005],n,s,l,r;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char po;
		cin>>a[i]>>po;
		for(int j=0;j<a[i];j++){
			b[s]+=po;
			s+=1;
		}
	}
	r=s-1;
	s=0;
	while(l<r){
		if(b[l]!=b[r]){
			s++;
		}
		l++;
		r--;
	}
	cout<<s;
	return 0;
} 

