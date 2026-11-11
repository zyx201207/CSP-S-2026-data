#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a_;
	char c_;
	string s;
	cin>>n;
	int sum=0,su=0;
	for(int i=1;i<=n;i++){
		cin>>a_>>c_;
		for(int j=1;j<=a_;j++){
			sum++;
			s[sum]=c_;
		}
	}
	int l=1,r=sum;
	for(int i=1;i<=sum/2;++i){
		if(s[l]!=s[r]) su++;
		l++;
		r--;
		
	}
	cout<<su<<s;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

