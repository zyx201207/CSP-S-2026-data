#include <iostream>
using namespace std;
int n;
long long a[100005],cnt;
char s[100005];
string s3,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s3+=s[i];
		}
	}
	for(long long i=0;i<s3.size()/2;i++)s1+=s3[i];
	if(s3.size()%2==0){
		for(long long i=s3.size()-1;i>=s3.size()/2;i--)s2+=s3[i];
	}
	else{
		for(long long i=s3.size()-1;i>s3.size()/2;i--)s2+=s3[i];
	}
	for(long long i=0;i<s1.size();i++){
		if(s1[i]!=s2[i])cnt++;
	}
	cout<<cnt;
	return 0;
}
