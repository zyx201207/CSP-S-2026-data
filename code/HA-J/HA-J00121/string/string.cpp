#include<bits/stdc++.h>
using namespace std;
long long n,j,ans;
struct node{
	long long x;
	string y;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
	}
	j=n;
	for(int i=1;i<j;i++){
		if(a[i].y!=a[j].y){
			if(a[i].x>a[j].x){
			    a[i].x-=a[j].x;
			    ans+=a[j].x;
			    i--;
				j--;
			}
			else if(a[i].x==a[j].x){
			    ans+=a[i].x;
				j--;
			}
			else if(a[i].x<a[j].x){
			    a[j].x-=a[i].x;
			    ans+=a[i].x;
			}
		}
		else{
			if(a[i].x>a[j].x){
			    a[i].x-=a[j].x;
			    i--;
				j--;
			}
			else if(a[i].x==a[j].x) j--;
			else if(a[i].x<a[j].x) a[j].x-=a[i].x;
		}
	}
	cout<<ans;
	return 0;
}
