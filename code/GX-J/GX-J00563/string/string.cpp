#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[100001];
string s[100001];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		if(i>0&&s[i]==s[i-1]) cnt++;
	}
	if(n<=1){
		cout<<0;
		return 0;
	}
	if(cnt==n){
		cout<<0<<endl;
		return 0;
	}
	int sum[10001];
	int j=0;
	for(int i=0;i<n;i++){
		if(i<n-1){
			if(s[i]==s[i+1]) sum[j]++;
			else j++;
		}
	}
	int a=2;
	for(int i=0;i<n;i++){
		if(sum[i]>=a) a=sum[i];
	}
	cout<<a;
	return 0;
}
