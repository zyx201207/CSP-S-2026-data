//GZ-J00141 自强中学 赵浩然 
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=0;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		
		for(int i=0;i<a;i++){
			s[k]=c;
			k++;
		}
	}
	long long cnt=0;
	int l=0,r=k-1;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	
	
	
	
	
	return 0;
}


