#include<bits/stdc++.h>
using namespace std;
int n;
long long l,sum;
string s=" ";
struct f{
	long long a;
	char b;
}e[111000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].b;
		l+=e[i].a;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=e[i].a;j++){
			s+=e[i].b;
		}
	}
	for(int i=1;i<=(l+1)/2;i++){
		if(s[i]!=s[l+1-i]){
//			cout<<s[i]<<" "<<s[l+1-i]<<"\n";
			sum++;
		}
	}
//	cout<<s[];
	cout<<sum;
	return 0;
}
