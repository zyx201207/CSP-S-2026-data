#include<bits/stdc++.h>
using namespace std;
char a[200001],b[200000001];
int ab[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios swnc_with_stdio(false);
	cin.tie();
	long n,tmp=0;cin>>n;
for(int i=0;i<n;i++){
	cin>>ab[i];
	cin>>a[i];
}
for(int i=0;i<n;i++){
	for(int j=0;j<ab[i];j++){
		b[i]=a[i];
	}
}
for(int i=0;i<n/2;i++){
	if(b[i]!=b[n-1-i])tmp++;
}cout<<tmp;	
}
