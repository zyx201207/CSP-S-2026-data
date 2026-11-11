#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
char b[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
			//cout<<1;
		}
	}
	long long i=0,j=s.size()-1,ans=0;
	//cout<<i<<' '<<j;
	while(i<j){
		//cout<<i<<' '<<j;
		if(s[i]!=s[j]){
			ans++;
			//cout<<ans;
		}
		i++;j--;
	}
	cout<<ans;
	return 0;
} 
