//GZ-J00487 遵义市第四初级中学 何思佳 Trick||Treat!
#include <bits/stdc++.h>
using namespace std;
int n;
char a[10000005],b[10000005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0;
		return 0;
	}
	string s="";
	for(int i=1;i<=n;i++){
		int d;
		char c;
		cin>>d>>c;
		for(int j=1;j<=d;j++){
			s+=c;
		}
	}
	for(int i=1;i<=s.size()/2;i++){
		a[i]=s[i];
	}
	for(int i=s.size();i>=s.size()/2+2;i--){
		b[i]=s[i];
	}
	int sum=0;
	for(int i=1;i<s.size()/2+1;i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0; 
}

