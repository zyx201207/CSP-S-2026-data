#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long a,n,size=0,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[size]=c;
			size++;
		}
	}
	for(int i=0;i<=(size-1)/2;i++){
		if(s[i]!=s[size-i-1])sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

