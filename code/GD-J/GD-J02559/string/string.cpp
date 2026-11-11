#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,maxn=INT_MIN,t,m;
bool b=1;
int ch[26];
string s;
bool pd(string s1){
	string s2=s1;
	reverse(s2.begin(),s2.end()); 
	if(s2==s1){
		return 1;
	}
	return 0;
} 
int number(string s3){
	int sum=0;
	string s4=s3;
	reverse(s4.begin(),s4.end()); 
	for(int i=0;i<s4.size();i++){
		if(s3[i]!=s4[i]){
			sum++;
		}
	}
	return sum;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		
		ch[c-'a']+=x;
		k+=x;
		while(x--){
			s+=c;
		}
	}
	if(pd(s)){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<26;i++){
		if(ch[i]>0){
			m++;
		}
		t=ch[i];
		maxn=max(maxn,ch[i]);
		if(ch[i]!=t){
			b=0;
		}
	}
	
		if(k-maxn==1){
			cout<<1<<endl;
			return 0;	
		}
		if(b==1 && m%2==0){
			cout<<k/2<<endl;
			return 0;
		}
		cout<<maxn<<endl; 
		
	return 0;
}
