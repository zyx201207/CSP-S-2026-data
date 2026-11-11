#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
unsigned long long n,a[N],len,ans;
char c[N];
string s; 


/*void cnt(unsigned long long x,unsigned long long y){
	if(a[x]<=a[y]){
		if(c[x]!=c[y]){
			ans+=a[x]; 
			a[y]-=a[x];
		}
		cnt(x+1,y);	
	}
	else{
		if(c[x]!=c[y]){
			ans+=a[y]; 
			a[x]-=a[y];
		}
		cnt(x,y-1);	
	}
	return;
}
*/


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		unsigned long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) 
			s+=c; 
	}
	len=s.size();
	string b;
	for(int i=0;i<len;i++)
		b+=s[len-i-1];
		
	if(len%2)
	for(int i=0;i<=len;i++)
		if(s[i]!=b[i]){
			ans++;
		}
	ans/=2;
	cout<<ans;
	return 0;
}







