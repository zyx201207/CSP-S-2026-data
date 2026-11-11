#include <iostream>
#include <string>
using namespace std;
const int N=20001;
long long ans=0;
struct node{
	int x;char t;
}c[N];
int n;
int min(int a,int b){
	if(a<b) return a;
	else return b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i].x>>c[i].t;
	int first=1,rear=n;
	while(first<rear){
		int num=min(c[first].x,c[rear].x);
		if(c[first].t==c[rear].t){
			c[first].x-=num;
			c[rear].x-=num;
		}
		else{
			c[first].x-=num;
			c[rear].x-=num;
			ans+=num;
		}
		if(c[rear].x==0) rear--;
		if(c[first].x==0) first++; 
	}
	cout<<ans;
	return 0;
}
