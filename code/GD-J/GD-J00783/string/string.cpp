#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n,a,len,k=0,sum,o=0;
char c;
string s,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[k]=c;
			k++;
		}
	}
	if(k%2==0){
		len=k/2-1;
		for(int i=0;i<=len;i++){
			m[i]=s[len-i];
		}
		for(int i=len+1;i<k;i++){
			if(m[o++]!=s[i]) sum++;
		}
		cout<<sum;
	}else{
		len=k/2;
		for(int i=0;i<len;i++){
			m[i]=s[len-i-1];
		}
		for(int i=len+1;i<k;i++){
			if(m[o++]!=s[i]) sum++;
		}
		cout<<sum;
	}
	return 0;
} 
