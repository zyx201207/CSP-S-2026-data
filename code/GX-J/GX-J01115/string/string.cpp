#include<bits/stdc++.h>
using namespace std;
int n;
long long x[200005],l,ans;
char s[200005],c[200000000000005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=l+1;j<=l+x[i];j++){
			c[j]=s[i];
		}
		l+=x[i];
	}
	if(l%2==0){
		for(int i=1,j=l;i<=l/2;j>=l/2+1;i++;j--){
			if(c[i]!=c[j]){
				ans++;
			}
		}
	}
	else{
		for(int i=1,j=l;i<=l/2;j>=l/2+2;i++;j--){
			if(c[i]!=c[j]){
				ans++;
			}
		}
	}
	cout<<ans;
    return 0;
}
