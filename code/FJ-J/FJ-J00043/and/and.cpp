#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
long long max=0;
long long n,m;
cin>>m>>n;
vector<long long>xl(n);
for(int i=0;i<n;i++){
	cin>>xl[i];
	
}
	int sum=0;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
sum=xl[i]&xl[j];
if(sum>=max){
	max=sum;
}
}}

cout<<max;
	return 0;
}
