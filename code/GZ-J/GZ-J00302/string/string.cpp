//GZ-J00302 遵义市第四中学 马跃腾 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,num=0,cnm;
string s;
struct zf{
	long long a;
	char c;
}ac[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ac[i].a>>ac[i].c;
		for(long long j=num+1;j<=num+ac[i].a;j++){
			s[j]=ac[i].c;
		}
		num+=ac[i].a;
	}
	for(long long i=1;i<=num/2;i++){
		if(s[i]!=s[num-i+1]){
			cnm++;
		}
	}
	cout<<cnm;
	return 0;
}
