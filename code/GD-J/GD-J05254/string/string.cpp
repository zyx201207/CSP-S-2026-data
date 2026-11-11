#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char s[5];
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a,l=0;
		char c;
		cin>>a>>c;
		for(int j=l;j<=a;j++){
			s[j]=c;
			l++;
		}
		long long len=l;
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i]){
				s[l-i]=s[i];
			}
		}
		
	}
	cout<<s;
	return 0;
}
