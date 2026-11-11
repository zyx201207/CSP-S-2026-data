#include<bits/stdc++.h>
using namespace std;
char st[10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num,cnt;
	cin>>n;
	//char st;
	for(int i=1;i<=n;i++){
		cin>>num>>st[i];
		cnt+=num;
	}
	for(int i=num;i>=1;i--){
		cout<<st[i];
	}
	
	return 0;
}
