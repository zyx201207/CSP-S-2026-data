#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string s=" ";
long long s_size;
int a[N];
char c[N];
bool dan=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]&&i>1){
			dan=0;
		}
	}
	if(dan){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)s+=c[i];
		s_size+=a[i];
	}
	long long ans=0;
	for(int l=1,r=s_size;l<r;l++,r--){
		if(s[l]!=s[r])ans++;
	}
	cout<<ans;
	
	return 0;
} 
