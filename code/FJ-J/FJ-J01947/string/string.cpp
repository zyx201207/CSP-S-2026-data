#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long lbj=1,b=0;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int j=lbj;j<=lbj+m-1;j++){
			s[j]=c;
		}
		lbj+=m;
		b+=m;
	}
	for(int i=1;i<=b;i++){
		cout<<s[i];
	} 
	long long ans=0;
	for(int i=1;i<=b/2;i++){
		if(s[i]!=s[b-i+1]){
			ans++;
		} 
	}
	cout<<ans;
	return 0;
}
