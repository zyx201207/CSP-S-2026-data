#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=500000000;
string ss;
char ch[200005];
ll n,c,m,s,t,p,mx;
ll len,a[200005],zm[27];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
//	freopen("string6.in","r",stdin);
//	freopen("string6.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];m+=a[i];
		zm[ch[i]-'a']+=a[i];
	}if(m<=M){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				ss+=ch[i];
			}
		}len=ss.size();
		for(int i=0;i<len;i++){
			if(ss[i]!=ss[len-i-1]){
				if(zm[ss[i]]>=zm[ss[len-i-1]]){
					ss[len-i-1]=ss[i];
					zm[ss[i]]++;s++;
				}else{
					ss[i]=ss[len-i-1];
					zm[ss[len-i-1]]++;s++;
				}
			}
		}cout<<s;
	}else{
		
//		for(int i=0;i<26;i++){
//			cout<<zm[i]<<' ';
//		}cout<<'\n';
		
		for(int i=0;i<26;i++){
			t=mx;mx=max(mx,zm[i]);
			if(mx!=t) p=i;
		}if(mx>=m/2) cout<<m-mx;
		
//		cout<<m<<' '<<mx<<'\n';
		
	}
	
	return 0;
}
