#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
char x;
long long a,n,sum1=0,sum2=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>x;
		for(long j=1;j<=a;j++){
			s1+=x;
		}
	}
	for(long long i=0;i<=s1.size()/2;i++){
		s2+=s1[i];
	}
	for(long i=s1.size()-1;i>=s1.size()/2;i--){
		s3+=s1[i];
	}
	if(s2==s3){
		cout<<0;
	}
	else{
		for(long long i=0;i<=s1.size()/2;i++){
		    if(s3[i]!=s1[i]){
		    	sum1++;
			}
	    }
	    for(long long i=s1.size()-1;i>=s1.size()/2;i--){
		    if(s2[i]!=s1[i]){
		    	sum2++;
			}
	    }
	    cout<<min(sum1,sum2);
	}
	return 0;
}
