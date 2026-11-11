//GZ-J00169 遵义市第一初级中学 梁悠然 
#include <iostream>
using namespace std;
string s,a;
int main (){
	long long n,m,x=0,b=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a[i];
		for(int j=b;j<=b+m;j++){
		b=b+m;
		s[j]=a[i];
	}
	}
	for(int i=1;i<=s.size();i++){
		for(int j=s.size();j>=i;j--){
			if(s[i]!=s[j]){
			   x++;
			}
		}
	if(i==s.size()/2){
		break;
	}
	}
	cout<<x;
}
