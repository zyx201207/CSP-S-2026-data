#include<bits/stdc++.h>
using namespace std;

long long a[500005],t[100005];
int main(){
	//GZ-J00154 遵义市朝阳小学 郑学宇
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		t[a[i]]=n-i+1;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
