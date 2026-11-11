#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string a[N],ans;
int cnt;
int jl[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>jl[i];
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=jl[i];j++){
			ans=ans+a[i];
		}
	}
	string t=ans;
	reverse(t.begin(),t.end());
	for(int i=0;i<ans.size()/2;i++){
		for(int j=ans.size()/2;j<ans.size();j++){
			if(ans[i]!=t[i]){
				ans[i]=t[i];
				cnt++;
			}
		}
		
	}
	cout<<cnt;
	
	return 0;
}

