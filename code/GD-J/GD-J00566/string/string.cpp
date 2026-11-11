#include <bits/stdc++.h>
using namespace std;

long long total=0,ans=0;
struct String{
	long long total;
	char c;
};
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	String a[n+1];
	for(int i=1;i<=n;i++){
		cin >> a[i].total >> a[i].c;
		for(int j=1;j<=a[i].total;j++){
			s+=a[i].c;
		}
	}
	int len=s.size();
	if(len%2==1){
		long long mid=len/2+1;
		string s1=s.substr(0,mid-1);
		string s2=s.substr(mid,len-mid);
		for(int i=0;i<mid-1;i++){
			if(s2[i]!=s1[len-i-1])ans++;
		}
		//cout << s1 << " " << s2 << "\n";
	}else{
		long long mid=ans/2;
		string s1=s.substr(0,mid);
		string s2=s.substr(mid,len-mid);
		for(int i=0;i<mid;i++){
			if(s2[i]!=s1[len-i-1])ans++;
		}
	}
	cout << ans;
	return 0;
} 
