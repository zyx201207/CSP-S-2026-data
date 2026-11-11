#include<bits/stdc++.h>
using namespace std;
int n;
struct st{
	int a;
	char c;
}s[200005];
int sum=0;
bool t=1;
int k=0;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
		for(int j=1;j<=s[i].a;j++){
			s1+=s[i].c;
		}
		if(i>1 && s[i].c!=s[i-1].c){
			t=0;
		}
	}
	if(t==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=sum/2;i++){
		if(s1[i]!=s1[sum-i+1]){
			k++;
		}
	}
	if(sum%2==0)k++;
	cout<<k;
	return 0;
}