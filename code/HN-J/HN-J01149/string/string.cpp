#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,num,tot=1,sum;
int ma=INT_MIN;
int a[1000001];
char c[1000001];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		ma=max(ma,a[i]);
	}
	sum=a[1]; 
	for(int i=0;i<num;i++){
		if(i>=sum){
			tot++;
			sum+=a[tot];
		}
		s+=c[tot];
	}
	if(s.size()%2==0){
		int t=s.size()/2;
		int sum=0,sum1=0;
		string s1="";
		for(int i=t-1;i>=0;i--){
			s1+=s[i];
		}
		int qwq=0;
		for(int i=t;i<s.size();i++){
			if(s1[qwq]!=s[i]){
				sum++;
			}
			qwq++;
		}
		cout<<sum;
		return 0;
	}else{
		int t=s.size()/2;
		int sum=0;
		string s1="";
		for(int i=t-1;i>=0;i--){
			s1+=s[i];
		}
		int qwq=0;
		for(int i=t+1;i<s.size();i++){
			if(s1[qwq]!=s[i]){
				sum++;
			}
			qwq++;
		}
		cout<<sum;
		return 0;
	}
	return 0;
} 
//10:00
/*
3
3 a
3 b
4 c
*/
