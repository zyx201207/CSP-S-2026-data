//GZ-J00277 贵阳市第一实验中学  吴皓轩
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,i=0,l=0,c=0;
	char a='0';
	char s[1000000];
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>i>>a;
		for(int j=0;j<i;j++){
			s[l]=a-'a'+1;
			l++;
		}
	}
	for(int j=l-1;j>=l/2;j--){
		if(s[j]!=s[l-j-1]){
			c++;
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
