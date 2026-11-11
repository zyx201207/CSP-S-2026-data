#include<bits/stdc++.h> 
using namespace std;
struct mm{
	long long a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,h=0;
	long long x=0;
	cin>>n;
	int  k=0,e=n-1;
	mm b[n];
	for(int i=0;i<n;i++){
		cin>>b[i].a>>b[i].c;
	}
	while(k<=n/2&&e>=n/2){
	if(b[k].c!=b[e].c){
		x+=min(b[k].a,b[e].a);
	}
		h=b[k].a;
		b[k].a-=b[e].a;
		b[e].a-=b[k].a;
	if(b[e].a<=0){
		e--;
	}
	if(b[k].a<=0){
		k++;
	}
}
cout<<x;
	return 0;
}
