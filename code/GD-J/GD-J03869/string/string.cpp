#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long l,len,a,j=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	while(l--){
		cin>>a>>c;
		len+=a;
		for(int i=1;i<=a;i++){
			s[j]=c;
			j++;
		}
	}
	int sum=0;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len+1-i]){
			sum++;
		}
	}
	cout<<sum;
}
