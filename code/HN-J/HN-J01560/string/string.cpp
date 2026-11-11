#include <bits/stdc++.h>
using namespace std;
const int m=1e8;
char a[m];
long long ans=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
int a1;
string s,s1="";
for(int i=1;i<=n;i++){
	cin>>a1>>s;
	for(int i=1;i<=a1;i++){
		s1=s1+s;
	}
}
for(int i=s1.size()/2-1,j=0;i>=0;i--){
	a[j]=s1[s1.size()-j-1];
	j++;
}
for(int i=0;i<s1.size()/2;i++){
	cout<<a[i]<<" "<<s1[i]<<endl;
	if(a[i]!=s1[i]){
		ans++;
	}
}
cout<<ans;
fclose(stdin);
fclose(stdout);
	return 0;
}
