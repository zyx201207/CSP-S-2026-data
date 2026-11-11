#include<bits/stdc++.h>
using namespace std;
int num[200005],m,n;
bool cmp(int l1,int l2){
	return l2>l1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
		for(int i=1;i<=n;i++){
		cout<<num[i]<<" ";
	}
	sort(num+1,num+n+1,cmp);
	cout<<num[m];
}
