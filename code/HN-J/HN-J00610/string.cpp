#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
bool b;
long long a[N];
long long ans,num;
string s;
void f(){
	long long sum=0;
	long long mn=0x3f3f3f3f;
	int s=-1;
	for(int i=1;i<=26;i++){
		if(a[i]<mn) mn=a[i];
	    if(a[i]>sum) sum=a[i];
		if(a[i]!=0) s+=1;
	}
	if(s>0){
		if(sum>ans/2) cout<<sum-mn;
		else cout<<sum;
	}else {
		cout<<0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		num+=x;
		a[c-'a'+1]+=x;
		if(num<5000000){
	       string s2(x,c);
	       s+=s2;
        }else b=1;
	}
	if(b==1) f();
	else{
	if(s.length()%2!=0){
		int z=s.length()/2+1;
		for(int i=1;i<=(s.length()-1)/2;i++){
			if(s[z-1]!=s[z+1]) ans++;
		}
	}else {
		int z=s.length()/2;
		for(int i=0;i<s.length()/2;i++){
			if(s[z-i]!=s[z+1+i]) ans++;
		}
	}
	cout<<ans;
}
	return 0;
} 
