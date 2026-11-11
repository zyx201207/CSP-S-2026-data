#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum=0;
	cin>>n;
	char s[n+2];
	long long t[n+2];
	for(long long i=1;i<=n;i++){
		cin>>t[i];
		cin>>s[i];
	}
	int y=0,z=0;
	for(long long i=1;i<=n;i++){
		if(t[i-y]==t[n-i+1+z]){
			if(s[i-y]==s[n-i+1+z]){
				t[i-y]-=t[n-i+1+z];
				continue;
			}else{
				sum+=t[i-y];
				t[i-y]-=t[n-i+1+z];
				continue;
			}		
		}else if(t[i-y]<t[n-i+1+z]){
			if(s[i-y]==s[n-i+1+z]){
				t[n-i+1+z]-=t[i-y];
				z++;
				continue;
			}else{
				sum+=t[i-y];
				t[n-i+1+z]-=t[i-y];
				z++;
				continue;
			}	
		}
		else{
			if(s[i-y]==s[n-i+1+z]){
				t[i-y]-=t[n-i+1+z];
				y++;
				continue;
			}else{
				sum+=t[n-i+1+z];
				t[i-y]-=t[n-i+1+z];
				y++;
				continue;
			}	
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
