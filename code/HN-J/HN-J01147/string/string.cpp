#include<bits/stdc++.h>
using namespace std;
int n,ans,hyz,lxt;
string s;
long long a[200005],sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		ans=a[i];
		for(int j=1;j<=ans;j++){
			s[i]=c[i];
		}
	}
	for(int i=1;i<=n;i++)
		sum+=a[i];
	for(int i=1;i<=n;i++)
		if(s[i]==c[1]) lxt+=1;
	if(lxt==sum){
		cout<<"0";
		return 0;
	}
	if(n%2!=0){
		for(int i=1;i<=sum/2+1;i++){
			if(s[sum-i+1]!=s[i]){
				hyz+=1;
			}
		}
	}
	else{
		for(int i=1;i<sum/2-1;i++){
			if(s[sum-i+1]!=s[i]){
				hyz+=1;
			}
		}
	}
	cout<<hyz;
	return 0;
} 
