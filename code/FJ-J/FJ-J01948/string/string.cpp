#include<bits/stdc++.h>
using namespace std;
int n,cnt;
char ch;
string str;
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt;
		cin>>ch;
		sum+=cnt;
		for(int j=1;j<=cnt;j++){
			str+=ch;
		}
	}
	for(int i=1;i<=sum/2;i++){
		if(str[i-1]!=str[sum-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
