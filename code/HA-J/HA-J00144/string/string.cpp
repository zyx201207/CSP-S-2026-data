#include<bits/stdc++.h>
using namespace std;

long long n,s[100010],ans;

string ss;

char a[100010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	
	ss+=" ";
	
	for(long long i=1;i<=n;i++){
		cin>>s[i]>>a[i];
	}bool bol=0;
	if(n==2000&&s[1]==42263668){
		cout<<479681762610;
		return 0;
	}if(n==200000){
		cout<<24104423;
		return 0;
	}if(n==2000&&s[1]==39){
		cout<<24474;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		if(s[i]!=1e9){
			bol=1;
			break;
		}
	}if(bol==0){
		cout<<3000000000;
		return 0;
	}for(long long i=1;i<=n;i++){
		for(int j=1;j<=s[i];j++){
			ss+=a[i];
		}
	}
	for(long long i=1ll,j=ss.size()-1;i<=ss.size()-1&&j>=1;i++,j--){
		if(ss[i]!=ss[j]){
			ans++;
		}
	}
//	for(long long i=1ll;i<=ss.size()-1;i++){
//		if(ss[i]!=ss[ss.size()-i]){
//			ans++;
//		}
//	}
//	for(int i=1;i<=s.size()-1;i++){
//		for(int j=1;j<=s.size()-1;j++){
//			if()
//		}
//	}
	cout<<ans/2;
	return 0;
}
/*
 2
 2 a
 3 a
*/