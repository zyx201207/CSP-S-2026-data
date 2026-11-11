#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+100;
int n;
string s="";
long long ans=0;
//long long l[maxn],r[maxn];
//long long len,ans=0;
//char w[maxn];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c; 
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int k=1;
	int len=s.length();
	if(s.length()%2==1){
		k=0;
		for(int i=len/2;i>=0;i--){
			if(s[i]!=s[i+2*k]){
				ans++;
			}
			k+=2;
		}
	}else{
		for(int i=len/2;i>=0;i++){
			if(s[i]!=s[i+k]){
				ans++;

			}
			k+=2;
		}
	}
	cout<<ans;
	return 0;
}


