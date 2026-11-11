#include<bits/stdc++.h>
using namespace std;
long long n,t,s,tt;
struct Q{
	long long x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		t+=a[i].x;
	}int l=1,r=n;
	while(l<r){
		if(a[l].x<a[r].x){
			if(a[l].c!=a[r].c){
				s+=a[l].x;
			}l++;
			a[r].x-=a[l-1].x;
			a[l-1].x=0;
		}else if(a[l].x>a[r].x){
			if(a[l].c!=a[r].c){
				s+=a[r].x;
			}r--;
			a[l].x-=a[r+1].x;
			a[r+1].x=0;
		}else{
			if(a[l].c!=a[r].c){
				s+=a[r].x;
			}r--;
			l++;
			a[l-1].x=0;
			a[r+1].x=0;
		}
	}cout<<s;
	return 0;
} 
