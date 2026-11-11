#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int n,a[N];
string s;
char b[N];
int ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int si=s.size();
	if(s.size()%2==0){
		for(int i=si/2;i<=si-1;i++){
			if(s[i]!=s[si-i-1]){
				ans++;
				//cout<<i<<" "<<s[i]<<" "<<si-s[i]-1<<endl;
			}
		}
	}else{
		for(int i=si/2+1;i<=si-1;i++){
			if(s[i]!=s[si-i-1]){
				ans++;
				//cout<<i<<" "<<s[i]<<" "<<si-s[i]-1<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
/**
using namespace std;
const int N=2e5+5;
int n,a[N];
char b[N];
int ans=0;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		a[i]+=a[i-1];
	}
	int al=a[n];
	
	return 0;
}
**/
