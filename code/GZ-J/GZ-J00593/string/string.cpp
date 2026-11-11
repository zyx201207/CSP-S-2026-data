//GZ-J00593 贵阳市第十八中学 向治隽逸  
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,ss=0;
	char c;
	string s,t;
	s.erase();
	t.erase();
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	if(s.size()%2==0){
		for(long long i=0;i<s.size()/2;i++){
			t+=s[i];
		}
		long long k=0;
		for(long long i=s.size()-1;i>=s.size()/2;i--){
			if(t[k]!=s[i]){
				ss++;
			}
			k++;
		}
	}
	else{
		for(long long i=0;i<s.size()/2;i++){
			t+=s[i];
		}
		int k=0;
		for(long long i=s.size()-1;i>=s.size()/2+1;i--){
			if(t[k]!=s[i]){
				ss++;
			}
			k++;
		}
	}
	cout<<ss;
	return 0;
}

