#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long s[n+5],sum=0,l=1,r=n,c;
	char k[n+5];
	for(int i=1;i<=n;i++){
		cin>>s[i]>>k[i];
	}
	while(l!=r){
		if(k[l]==k[r]){
			c=min(s[l],s[r]);
			if(s[l]-c==0){
				l++;
				s[r]-=c;
			}
			else if(s[r]-c==0){
				r--;
				s[l]-=c;
			}
		}
		else if(k[l]!=k[r]){
			c=min(s[l],s[r]);
			sum+=c;
			if(s[l]-c==0){
				l++;
				s[r]-=c;
			}
			else if(s[r]-c==0){
				r--;
				s[l]-=c;
			}
		}
	}
	cout<<sum;
	return 0;
}
