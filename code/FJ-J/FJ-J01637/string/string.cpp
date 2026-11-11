#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long lst=0;
	long long last=0;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		lst+=a;
		for(int j=last;j<lst;j++){
			s[j]=b;
		}
		last=a+1;
	}
	long long mid=(lst+1)/2-1;
	long long cnt1=0;
	if(lst%2==0){
		for(int i=0;i<=mid;i++){
			if(s[i]!=s[lst-i-1]){
				cnt1++;
			}
		}
	}else{
		for(int i=0;i<mid;i++){
			if(s[i]!=s[lst-i-1]){
				cnt1++;
			}
		}
	}
	cout<<cnt1;
	return 0;
}
