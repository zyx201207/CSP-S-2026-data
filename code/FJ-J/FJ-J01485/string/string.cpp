/*
*/
#include<bits/stdc++.h>
using namespace std;
long long n,l,r,x,y,sum;
struct st{
	long long x;
	string s;
}a[212345];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
	}l=1,r=n;
	while(l<r){
		if(a[l].x-x>a[r].x-y){
			if(a[l].s!=a[r].s) sum+=(a[r].x-y);
			x+=(a[r].x-y);
			y=0;
			r--;
		}else if(a[l].x-x<a[r].x-y){
			if(a[l].s!=a[r].s) sum+=(a[l].x-x);
			y+=(a[l].x-x);
			x=0;
			l++;
		}else{
			if(a[l].s!=a[r].s) sum+=(a[l].x-x);
			x=0,y=0;
			l++,r--;
		}
	}cout<<sum;
	return 0;
} 
