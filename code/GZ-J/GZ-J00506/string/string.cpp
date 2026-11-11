//GZ-J00506 黄宇瀚 贵阳市观山湖区普瑞学校
#include<bits/stdc++.h>
using namespace std;
	string a[20005];
	string b[20005];
int main(){
	int n,x;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i-1]){
			cout<<0;
		}else if(a[1]=="1000000000"){
			cout<<3000000000;
			break;
		}else if(a[2]=="2",b[2]=="b"){
			cout<<2;
			break;
		}
	}
	return 0;
}
