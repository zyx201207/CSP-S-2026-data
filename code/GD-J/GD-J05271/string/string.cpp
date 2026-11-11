#include<bits/stdc++.h>
using namespace std;
int n;
long long s[100000010];
char st[10000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>st[i];
	}
	long long l=1,r=n,sum=0;
	while(l<=r){
		if(st[l]==st[r]){
			r--;l++;
			continue;
		}
		if(st[l]!=st[r]&&s[l]==s[r]){
			sum+=s[r];
			l++,r--;
		}
		else if(s[l]>s[r]){
			sum+=s[l]-s[r];
			s[l]-=s[r];
			r--;
		}
		else{
			sum+=s[r]-s[l];
			s[r]-=s[l];
			l++;
		}
		
	}
	cout<<sum;
	return 0;
} 
