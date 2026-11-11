#include<bits/stdc++.h>
using namespace std;

const int M=2e5+5;
int a[M];
string tw[M];//二进制 

//bool to_base(int x){
//	string s;
//	
//	while(x!=0){
//		int y=x%2;//余数
//		x= 
//	}
//}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	cout<<a[1]; 
	return 0;
} 
