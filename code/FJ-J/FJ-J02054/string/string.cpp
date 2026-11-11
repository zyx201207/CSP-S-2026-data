#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans =0;
	long long siz = 0;
	string s ="0";
	cin>>n;
	for(int i=1;i<=n;i++){
	 cin>>a[i]>>c[i];
	 siz +=a[i];
	 for(int j=1;j<=a[i];j++){
	 	s+=c[i];
	 } 
	 
	}
	if(siz%2==0){
		ans++;
		for(int i=1;i*2<=siz;i++){
			if(s[i] != s[siz-i]) {
			ans++;	
			s[siz-i] = s[i];
			}	
		}
	}else {
		for(int i=1;i*2+1<=siz;i++){
		
			if(s[i] != s[siz-i+1]) {
			ans++;	
			s[siz-i+1] = s[i];
			
		 }
		}
	}
    cout<<ans;
	return 0;
}
