#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
		}
	}
	long long ans=0;
    int p=0,q=s.size()-1;
    while(p<q){
    	if(s[p]!=s[q]){
    		ans++;
		}
		p++;
		q--;
	}
	cout<<ans<<endl;
	return 0;
}

