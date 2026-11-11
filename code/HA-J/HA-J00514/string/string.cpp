#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,len;
string s;
char c;
int a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<(len+1)/2;i++){
		if(s[i]!=s[len-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
