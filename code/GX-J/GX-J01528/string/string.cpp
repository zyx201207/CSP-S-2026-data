#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(long long i=0;i<n;i++){
		long long m;
		cin>>m;
        string c;
        cin>>c;
        for(long long j=0;j<m;j++){
			s=s+c;
	    }
	}
	long long len=s.size();
	long long j=len-1;
	for(long long i=0;i<=len-1;i++){
		if(i>=j){
			break;
		}
		if(s[i]!=s[j]){
			ans++;
		}
		j--;
	}
	cout<<ans;
    return 0;
}
