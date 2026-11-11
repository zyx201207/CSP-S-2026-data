#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a,ans,num,j;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c; 
	}
//	cout<<s;
	for(int i=0;i< floor(s.size()/2);i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
//	for(int i=1;i<=n;i++){
//		if(cnt+a[i]<=num/2)	{
//			cnt+=a[i];
//			continue;
//		}
//		else if(cnt>num/2){
//			
//		}
//	}
	return 0;
}
