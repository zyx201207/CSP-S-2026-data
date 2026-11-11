#include<bits/stdc++.h>
using namespace std;
int n,a,num,c,sum;
char t;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>t;
		for(int j=1;j<=a;j++){
			num++;
			s[num]=t;
		}
	}
	c=num/2;
	for(int i=1;i<=c;i++){
		if(s[i]!=s[num-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
