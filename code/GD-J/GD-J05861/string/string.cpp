#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int n;
long long a[N],cnt;
string s="";
char c[N];
long long sum;
string re(string s){
	string ss="";
	for(int i=s.size()-1;i>=0;i--){
		ss+=s[i];
	}
	return ss;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cin>>c[i];
    	for(int j=1;j<=a[i];j++){
    		s+=c[i];
		}
	}
	string ss=re(s);
//	for(int i=1;i<=sum;i++){
//		cout<<c[i];
//	}
    for(int i=0;i<s.size()/2;i++){
    	if(s[i]!=ss[i]) sum++;
	}cout<<sum;
	return 0;
} 
