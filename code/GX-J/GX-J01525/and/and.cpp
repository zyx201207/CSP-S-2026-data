#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005].so[100005];
string s[1000005];
void dfs(int k){
	if(k==n){
		retunn 0;
		}
		else{
			k = 2*n-1;
			}
	}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long l[1005];
	vector <long long> s(1005);
	for(int i=0;i<n;i++){
		cin>>l[i];
		}
	for(int i=0;i<m;i++){
		s[i]=max(l[i],l[i+2]);
		}
		int cnt=0;
	for(int i=0;i<n;i++){
		cnt = min(s[i],s[i+1]);
		}
		cout<<cnt;
	return 0;
	}

