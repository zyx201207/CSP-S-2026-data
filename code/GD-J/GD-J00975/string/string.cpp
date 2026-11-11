#include<bits/stdc++.h>
using namespace std;
long long w[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>s[i];
	}
	long long ans=0;
	int j=n,i=1;
	while(i<=j){
		if(s[i]==s[j]){
			if(w[i]>w[j]){
				w[i]-=w[j];
				j--;
			}else if(w[i]==w[j]){
				i++;
				j--;
			}else{
				w[j]-=w[i];
				i++;
			}
		}else{
			if(w[i]>w[j]){
				ans+=w[j];
				w[i]-=w[j];
				j--;
			}else if(w[i]==w[j]){
				ans+=w[i];
				i++;
				j--;
			}else{
				ans+=w[i];
				w[j]-=w[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
