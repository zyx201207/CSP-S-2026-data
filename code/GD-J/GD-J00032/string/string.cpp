#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n;
	cin>>n;
	long long a,len=0;
	char c;
	string s1=" ",s2=" ";
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=a;j++){
			s1+c;
		}
	}
	if(n==1){
		cout<<"0";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=len;i--){
		s2+s1[len-i];
		if(s2[i]!=s1[i]) cnt++;
	}
	if(s1==s2) cout<<"0";
	else cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
