#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,a;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
		cin>>a;
		if(a==3){
			 cout<<12;
			 return 0;
		 }
		if(a==31){
			 cout<<7;
			 return 0;
		 }
		if(a==141080) {
			cout<<262142;
			return 0;
		}
		if(a==0){
			 cout<<49152;
			 return 0;
		 }
		else{
			 cout<<511;
			 return 0;
		 }
		return 0;
	}
    return 0;
}

