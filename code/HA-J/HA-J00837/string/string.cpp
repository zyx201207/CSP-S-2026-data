#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long n,sum=0,cnt=0,maxn=-1;
int a[200005];
bool f=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s2;
		cin>>a[i];
		cin>>s2;
		if(a[i]>maxn){
			maxn=a[i];
			s1=s2;
		}
		int L=s.size();
		if(s[L-1]!=s2[0]&&L!=0){
			f=1;
		}
		for(int j=1;j<=a[i];j++){
			s+=s2;
		}
	}
	if(n==1) f=0;
	if(f==1){
		long long L=s.size();
		cnt=L-1;
		for(long long i=0;i<L;i++){
			if(s[L/2-1]==s[L/2]&&L%2==0) cnt--;
			if(L%2!=0) cnt--; 
			for(long long j=L/2;i>=0;i--){
				if(s[i]==s[j]) cnt--;
			}
		}
		if(cnt<=0) cout<<0;
		else cout<<cnt;
	}else if(f==0){
		cout<<0;
	}
	
	return 0;
}

