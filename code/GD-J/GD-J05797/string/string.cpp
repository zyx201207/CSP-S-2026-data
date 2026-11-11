#include<bits/stdc++.h>
using namespace std;
int n;
long long t[200005],cnt=0;
char s[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		ans+=t[i];
		cin>>s[i];
		t[i]=t[i]+t[i-1];

	}

	for(int i=1;i<=ans/2;i++){
		char a;
		char b;
		for(int j=1;j<=n;j++){
			if(i>t[j-1]&&i<=t[j]){
				a=s[j];
				break;
			}
		}
	
		for(int j=n;j>=1;j--){
			if((ans-i+1)>t[j-1] && (ans-i+1)<=t[j]){
				b=s[j];
				break;
			}
		}
		if(a!=b){
			cnt++;
		}		
	}

	cout<<cnt;
}
