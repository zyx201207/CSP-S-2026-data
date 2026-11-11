#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n=0;
	cin>>n;
	long long int a[200001]={};
	char b[200001]={};
	string s;
	for(long long int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		for(long long int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==-1){
			continue;
		}
		for(int j=i+1;j<n;j++){
			if(b[i]==b[j]){
				a[i]+=a[j];
				a[j]=-1;
				b[j]='1';
			}
		}
	}
	long  long cnt=0;
	for(long long int i=0;i<s.length();i++){
		if(s[i]!=s[s.length()-1-i]){
			long long int num1=0;
		 	long long int num2=0;
			for(long long int j=0;j<n;j++){
				if(b[j]==s[i]){
					num1=j;
				}
				if(b[j]==s[s.length()-1-i]){
					num2=j;
				}
			}
			if(a[num1]>=a[num2]){
				s[s.length()-1-i]=s[i];
				a[num1]++;
				a[num2]--;
			}else{
				s[i]=s[s.length()-1-i];
				a[num1]--;
				a[num2]++;
			}	
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
