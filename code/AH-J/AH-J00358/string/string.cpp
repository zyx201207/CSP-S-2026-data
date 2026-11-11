#include<bits/stdc++.h>
using namespace std;
string s;
int sum=0;
int num=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		sum+=a;
	}
	for(int i=0;i<=sum/2-1;i++){
		if(s[i]!=s[sum-1-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
