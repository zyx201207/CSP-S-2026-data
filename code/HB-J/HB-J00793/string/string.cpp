#include<bits/stdc++.h>
using namespace std;
long long n,ls,z,asw;
struct T{
	long ip;
	char id;
}a[200500];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i].ip>>a[i].id;
	}
	int l=1,r=n;
	while(l<r){
		int m=min(a[l].ip,a[r].ip);
		if(a[l].id!=a[r].id){
			asw+=m;
			a[l].ip-=m;
			a[r].ip-=m;
		}
		else{
			a[l].ip-=m;
			a[r].ip-=m;
		}
		if(a[l].ip==0) l++;
		if(a[r].ip==0) r--;
	}
	cout<<asw;
    return 0;
}
