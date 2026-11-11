#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	string s;
	char b;
	long long n,m=0,a,num=0;cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		while(a--){
			s+=b;
		}
	}
	int left,right;
	left=0;
	right=s.size();
	while(left<right){
		if(s[left]!=s[right]){
			num++;
			s[left]=s[right];
		}
		left++;
		right--;
	}
	cout<<num;
	return 0;
}