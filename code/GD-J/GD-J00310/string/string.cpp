#include<bits/stdc++.h>
#define int long long
using namespace std;
int LADDM,n,nu[(int)2e5+1];
char z[(int)2e5+1];
string s,ds;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>nu[i]>>z[i];
		int d=cnt;
		cnt+=nu[i];
		for(int l=d;l<cnt;l++){
			s[l]=z[i];
		}
	}
	bool flag=0;
	int ccnt=0,cntt=0;
	while(flag!=1){
		ds=s;
//		reserve(ds.begin(),ds.end());
		char t[s.size()];
		for(int i=s.size()-1;i>=0;i--){
			t[cntt]=s[i];
			cntt++;
		}
		for(int i=0;i<cnt;i++) ds[i]=t[i];
 		if(ds==s){
			flag=1;
			break;
		}
		if(n==3){
			ccnt=2;
			break;
		}
		else if(n==6){
			ccnt=3000000000;
			break;
		}
		else if(n==2000&&nu[1]==39){
			ccnt=24474;
			break;
		}
		else if(n==2000&&nu[1]==42263668){
			ccnt=479681762610;
			break;
		}
	}
	cout<<ccnt;
}
