#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,answer;
string hw,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s=s+c;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++) hw=s[i]+hw;
	int cnt=0;
	if(len%2!=0) cnt++;
	for(int i=len/2+cnt,j=0;i<len;i++,j++) if(s[i]!=hw[j]) answer++;
	cout<<answer;
	fclose(stdin);
	fclose(stdout);  
	return 0;
}