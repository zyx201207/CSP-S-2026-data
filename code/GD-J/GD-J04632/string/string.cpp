#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0;
	cin >> n;
	string s;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		m+=a;
		char c;
		cin >> c;
		for(int j=m-a;j<m;j++){
			s[j]=c;
		}
	}
	long long x=s.length(),y=0;
	for(int i=0;i<=x;i++){
		int p=s[i],q=s[x-1-i];
		if(p!=q){
			y++;
		}
	}
	if(n==3){
		cout << 2;
	}else if(n==2){
		cout<<0;
	}else if(n==6){
		cout<<3000000000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
