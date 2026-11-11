//GZ-J00688 遵义市第十二中学 刘俊逸 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n,b=0,c=0,d=0;
	cin>>n;
	long long l[n+1];
	string s,a;
	if(n==1){
		cout<<'0';
	}
	else{
		for(int i=0;i<n;i++){
			cin>>l[i]>>a[i];
			d=d+l[i];
			for(int j=1;j<=l[i];j++){
				s=s+a[i];
			}
		}
		for(int i=0;i<d;i++){
			if(s[i]!=s[d-i-1]){
				b=1;
				c=d/l[i];
				break;
			}
		}
		if(b==1){
			cout<<c;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
