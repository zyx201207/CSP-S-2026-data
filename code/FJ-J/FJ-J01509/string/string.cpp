#include<bits/stdc++.h>
using namespace std;
int n,a[10001];
char c[10001];
string s[10001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=a[i];i++){
		s[i]+=c[i];
	}
	for(int i=1;i<=n;i++){
		string s1=s[i];
		if(s1.size()%2!=0){
			int sum=(s1.size()-1)/2;
		    string s2=substr(sum+1,a[i]-1);
		    string s3=substr(0,sum-1)
		    resever(s2.begin(),s2.end());
		    if(s2==s3){
		    	cout<<"0";
			}
		}
		else{
			int sum=s1.size()/2;
		    string s2=substr(sum,a[i]-1);
		    string s3=substr(0,sum-1)
		    resever(s2.begin(),s2.end());
		    if(s2==s3){
		    	cout<<"0";
			}
		}
		
	}
	return 0;
}
