#include<bits/stdc++.h>

using namespace std;
long long n,a,len,cnt,s[2000005];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=0;j<a;j++){
			s[len]=int(c);
			len++;
		}
	}
	for(long long i=0,j=len-1;i<j;i++,j--){
		if(s[i]!=s[j]&&i!=j)cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
