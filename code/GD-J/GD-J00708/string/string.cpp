#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005];
string s,s1;
char t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>m>>t;
    	a[int(t)]+=m;
    	for(int j=0;j<m;j++){
    		s+=t;
		}
	}
	int l=0,r=s.size();
	while(l<=r){
		s1[l]=s[r];
		s1[r]=s[l];
		r--;
		l++;
	}
	if(s==s1){
		cout<<0;
		return 0;
	}
	return 0;
}
