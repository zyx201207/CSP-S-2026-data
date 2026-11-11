#include<bits/stdc++.h>
using namespace std;
string s,s1,sa;
long long n,cnt=0,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>k>>s1;
		while(k--)s+=s1;
	} 
	sa=s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]!=sa[len-1-i]){
			swap(sa[i],sa[len-i-1]);cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);fclose(stdout);
	return 0;
}
