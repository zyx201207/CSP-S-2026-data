#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0,b=0,ans;
	long long a[n];
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		l+=a[i];
	}
	ans=l-l/2;
	for(int i=0;i<n;i++){
		b+=a[i];
		if(b>=l-l/2+1){
			ans-=b-l+l/2-1;
			for(int j=i+1;j<n;j++){
				if(s[i-j]==s[i+j]){
					ans-=a[j];
				}
			}
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
