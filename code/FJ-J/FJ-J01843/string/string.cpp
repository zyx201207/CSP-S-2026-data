#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long int n;
	cin>>n;
	long long int ai;
	char ci;
	long long int t=0;
	for(int i=0;i<n;i++){
		cin>>ai>>ci;
		for(int j=t;j<t+ai;j++){
			s[j]=ci;
		}
		t=t+ai;
	}
	long long int l=0,r=t-1,p=n/2;
	long long int any=0;
	for(int i=0;i<=p;i++){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			s[l]=s[r];
			l++;
			r--;
			any++;
		}
	}
	cout<<any;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
