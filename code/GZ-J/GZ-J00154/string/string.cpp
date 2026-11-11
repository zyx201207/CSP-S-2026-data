#include<bits/stdc++.h>
using namespace std;

int main(){
	//GZ-J00154 遵义市朝阳小学 郑学宇
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0,n;
	string s="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s=s+c;
		}
	}
	for(long long i=0;i*2<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
