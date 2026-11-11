//GZ-J00706 遵义市第十二中学 张明韬
#include<bits/stdc++.h>
using namespace std;
string a,ab;
long long sum,mid,n,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		sum=sum+b;
		cin>>ab;
		for(int j=1;j<=b;j++){
			a=a+ab;
		}
	}
	mid=sum/2;
	bool ans;
	for(int i=0;i<sum;i++){
		if(a[i]==a[sum-i-1]) {
			ans=1;
		}
		else{
			ans=0;
			break;
		}
	}
	if(ans){
		cout<<0;
		return 0;
	}
	cout<<mid;
	return 0;
} 
