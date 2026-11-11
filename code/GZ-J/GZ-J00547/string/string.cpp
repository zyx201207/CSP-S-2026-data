//GZ-J00547 张运航 贵阳市第十九中学 
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int s,d;
	char a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d>>a;
		s+=d;
		
	}
	cout<<int(s/2);
	return 0;
}
