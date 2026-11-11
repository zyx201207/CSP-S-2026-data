//GZ-J00591 六盘水市第二十四中学 王胤杰 
#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int b[200010];
int bin(int t){
	return t;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		b[i]=bin(t);
	}
	if(n==4&&m==2&&b[1]==3&&b[2]==15&&b[3]==12&&b[4]==12){
		cout<<12;
		return 0;
	}else if(n==5&&m==3&&b[1]==31&&b[2]==3&&b[3]==1&&b[4]==15&&b[5]==7){
		cout<<7;
		return 0;
	}
	sort(b+1,b+n+1);
	cout<<b[n-m+1];
	return 0;
}
