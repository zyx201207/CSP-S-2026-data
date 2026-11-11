#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0; i<n; i++){
		for(long long j=a[i]; j>0; j--){
			s+=b[i];
		}
	}
	int x=s.size();
	bool flag=0;
	long long cnt=0;
	long long ans=0;
	if(x%2==0){cnt=x/2;ans=cnt+1;}
	if(x%2!=0){cnt=(x+1)/2-1;ans=cnt+2;}
	if(x==1){
		cout<<0;
		return 0;
	}
	if(x==2){
		if(s[0]==s[1]){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	for(long long i=0; i<cnt; i++){
		if(s[cnt-i-1]==s[ans+i-1])flag=1;
		else{
			flag=0;
			break;
		}
	}    
	if(flag){
		cout<<0;
		return 0;
	}
	long long num=0;
	for(long long i=0; i<cnt; i++){
		if(s[cnt-i-1]!=s[ans+i-1])num++;
	}
	cout<<num;
	return 0;
} 
