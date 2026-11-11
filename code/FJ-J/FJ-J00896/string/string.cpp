#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200050;
int a[N];
string s[N];
void solve(){
	int n;
	cin>>n;
	string ss;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		ss+=s[i];
	}
	cout<<ss<<endl;
	int bj=0;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			bj=1;
			break;
		}
	}
	cout<<bj<<endl;
	if(bj==1){
		string sss;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				sss+=s[i];
			} 
		}
		int sum=0;
        int l=0,r=sss.size()-1;
        while(l<=r){
        	if(sss[l]!=sss[r]){
        		sum++;
        		l++;
        		r--; 
        	}
        	else{
        		l++;
        		r--;
        	}
        }
		cout<<sum;
	}
	if(bj==0){
		int ans=0;
        int l=0,r=ss.size()-1;
        while(l<=r){
        	if(ss[l]!=ss[r]){
        		ans+=a[r];
        		l++;
        		r--; 
        	}
        	else{
        		l++;
        		r--;
        	}
        } 
	    cout<<ans;
    }
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
