#include<bits/stdc++.h>
using namespace std;
int l1[200020];
int l2[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l1[i];
	}
	sort(l1+1,l1+n+1);
	for(int i=n;i>=n-m+1;i--){
		l2[n-i+1]=l1[i];
	}
	for(int i=2;i<=m;i++){
		if(i==2){
			num+=l2[2]&l2[1];
		}
		else{
			num=num&l2[i];
		}
	}
	cout<<num;
	return 0;
}
