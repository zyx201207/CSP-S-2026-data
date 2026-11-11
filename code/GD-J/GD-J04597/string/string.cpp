#include<bits/stdc++.h>
using namespace std;
string sw;
int u[100050];
long long ishui(string w,long long num){
	long long f=0;
	if(num%2==0){
		for(long long i=0;i<num/2;i++){
			if(w[i]!=w[num-i-1]){
				f++;
			}
		}
		return f;
	}else{
		for(long long i=0;i<(num-1)/2;i++){
			if(w[i]!=w[num-i-1]){
				f++;
			}
		}
		return f;
	}
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		long long a;
		char s;
		
		cin>>a>>s;
		cnt+=a;
		u[i]=a;
		for(long long i=1;i<=a;i++){
			sw+=s;
		}
    }

	cout<<ishui(sw,cnt);
	return 0;
} 
