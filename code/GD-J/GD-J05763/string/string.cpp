#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
}S[100001];
long long n=0;
long long sum=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long b=0,e=n-1;
	for(long long i=0;i<n;i++){
		cin>>S[i].a>>S[i].c;
		sum+=S[i].a;
	}	
		sum/=2;
		long long x=S[b].a,y=S[e].a;
		if(sum%2==1)sum-=1;
		while(sum){
			if(S[b].c==S[e].c){
				if(x>y){
					x-=y;
					sum-=y;
					y=S[e--].a;
				}
				else if(x<y){
					y-=x;
					sum-=x;
					x=S[b++].a;
				}else{
					sum-=x;
					x=S[b++].a,y=S[e--].a;
				}
			}
			else{
				if(x>y){
					x-=y;
					sum-=y;
					ans+=y;
					y=S[e--].a;
				}
				else if(x<y){
					y-=x;
					sum-=x;
					ans+=x;
					x=S[b++].a;
				}
				else{
					sum-=x;
					ans+=x;
					x=S[b++].a,y=S[e--].a;
				}
			}
		}
		cout<<ans;
	return 0;
}
