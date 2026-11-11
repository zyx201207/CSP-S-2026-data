#include<bits/stdc++.h>
using namespace std;
int main(){
	fopen("and.in","r",stdin);
	fopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin>>a>>b;
	int s[10000]={};
	for(int i = 1;i <= a;i += 1){
		cin>>s[i];
	}
	sort(s+1,s+1+a);
	int sum = s[a];
	for(int i = a;i > a-b;i--){
		sum = (sum&s[i]);
	}
	cout<<sum;
	return 0;
} 
