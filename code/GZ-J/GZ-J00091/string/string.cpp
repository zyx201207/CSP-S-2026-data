//GZ-J00091 习水县第九中学 袁贵仁 
#include<bits/stdc++.h>
using namespace std;
long long n,a,b,cnt=0;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>s1[i];
		if(s1[i]==s1[i-1]){
			cout<<0;
			return 0;
		}
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
