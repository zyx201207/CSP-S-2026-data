#include<bits/stdc++.h>
using namespace std;
long long t,a[10000000000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>t;
    while(t--){
    	long long n;
    	char a;
    	cin>>n>>a;
    	while(n--){
    		s+=a;
		}
	}
    for(long long i=0,j=s.size()-1;i<=j;i++,j--){
    	if(s[i]!=s[j]) {
    		a[0]++;
    		for(int k=0;k<10000000000000;k++){
    			a[1]+=a[0]/10;
    			a[0]%=10;
			}
  		}
	}
	long long m=10000000000000;
	while(a[m-1]==0&&m>1) m--;
	for(int i=m-1;i>=0;m--){
		cout<<a[i];
	}
    return 0;
}
