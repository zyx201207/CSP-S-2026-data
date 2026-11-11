//GZ-J00303 遵义四中 郑安迪 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,len=0;
	cin>>n;
	int a;
	char b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		len+=a;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	int sum=0;
	int x=0,y=len-1;
	while(x<y){
		if(s[x]!=s[y])sum++;
		x++;
		y--;
	}
	cout<<sum;
	return 0;
}

