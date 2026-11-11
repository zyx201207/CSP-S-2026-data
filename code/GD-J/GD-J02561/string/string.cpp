#include<bits/stdc++.h>
using namespace std;
long long n;
struct St{
	int a;
	char b;
};
int main(){
	long long co=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	St S[n+5];
	for(long long i=0;i<n;i++){
		cin>>S[i].a>>S[i].b;
	}
	long long l=0,r=n-1;
	while(l<r){
		if(S[l].b!=S[r].b){
			if(S[l].a>S[r].a){
				co+=S[r].a;
				S[l].a-=S[r].a;
				r--;
			}else if(S[r].a>S[l].a){
				co+=S[l].a;
				S[r].a-=S[l].a;
				l++;
			}else{
				co+=S[l].a;
				l++;
				r--;
			}	
		}else{
			if(S[l].a>S[r].a){
				S[l].a-=S[r].a;
				r--;
			}else if(S[r].a>S[l].a){
				S[r].a-=S[l].a;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<co;
	return 0;
}
