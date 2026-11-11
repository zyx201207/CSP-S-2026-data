#include<bits/stdc++.h>
using namespace std;
long long a[10000010];
long long ans;
char s[10000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	long long j=n,i=1;
	for(;j>i;){
		if(s[i]==s[j]){
			if(a[i]==a[j]){
				i++;
				j--;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
		else if(s[i]!=s[j]){
			if(a[i]==a[j]){
				ans+=a[i];
				i++;
				j--;
			}
			else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	//1
	cout<<ans;
	return 0;
} //Trick||Treat!
