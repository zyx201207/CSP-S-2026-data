#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,bi=0,ans=0;
	cin>>n;	
	long long a[N],b[n]={0};
	string s;
	for(long long i=0;i<n;i++){
		cin>>b[i];
		cin>>s[i];
		bi+=b[i];
	}
	long long ba=bi%2;
	long long bz=bi/2+ba;	
	ans=bi-bz;
	int flag=1;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			if(s[i]!=s[j]){
				flag=0;
				break;
			}
	}
	}
	if(flag){
		cout<<0;
	}
	else{
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
