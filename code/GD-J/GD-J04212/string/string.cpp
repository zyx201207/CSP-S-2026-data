#include<bits/stdc++.h>
using namespace std;
struct ac_{
	long long a;//length
	char c;//words
}ac[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>ac[i].a>>ac[i].c;
	}
	long long l=0,r=n-1;
	while(l<r){
		if(l>=r) break;
		if(ac[l].c!=ac[r].c){
			if(ac[l].a>ac[r].a){
				ans+=ac[r].a;
				ac[l].a-=ac[r].a;
				--r;
			}
			else{
				ans+=ac[l].a;
				ac[r].a-=ac[l].a;
				++l;
			}
			
		}
		else{
			if(ac[l].a>ac[r].a){
				ac[l].a-=ac[r].a;
				--r;
			}
			else{				
				ac[r].a-=ac[l].a;
				++l;
			}
		}
	}
	cout<<ans;
	return 0;
}
