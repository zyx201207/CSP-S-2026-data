//GZ-J00497 遵义市第八中学 龙长鑫 
#include<bits/stdc++.h>
using namespace std;
long long n,a=INT_MIN,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>a;
	while(n--){
		cin>>b;
		a=max(a,b);
	}
	cout<<a;
	return 0;
}

