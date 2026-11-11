#include<bits/stdc++.h>
using namespace std;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int flag=1;
	long long sum=0;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		sum+=b;
		cin>>c[i];
		for(int j=1;j<=b;j++){
			s+=c[i];
		}
		if(i>=2){
			if(c[i]!=c[i-1]){
				flag=-1;
			}
		}
	}
	if(n==1 || flag==1){
		cout<<0;
		return 0;
	}
	long long l=0,r=sum-1;
	long long ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		//cout<<s[l]<<" "<<s[r]<<" "<<1<<endl;
		//cout<<l<<" "<<r<<endl;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
