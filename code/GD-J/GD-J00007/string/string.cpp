#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//  std::styc_with_stdio();
    cin.tie(0);
	long long n,m,x,cnt;
	string S,a;
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>a;
		for(long long j=1;j<=m;j++){
			S+=a;
		}
	}
	long long y=S.size();
	if(y%2){
		for(long long i=0;i<y/2;i++){
			if(S[i]!=S[y-1-i]){
				cnt+=1;
				S[i]=S[y-1-i];
			}
		}
	}
	cout<<cnt;
	return 0;
}
