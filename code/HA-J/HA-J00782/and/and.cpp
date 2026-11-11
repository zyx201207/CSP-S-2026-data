#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num,ans=0,maxi=0,x=1;
vector<long long> v,v1;
long long a[1000009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	for(int j=0;j<n;j++){
	int s;
		for(int k=j;k<j+m;k++){
			if(k==j){
				s=a[k];
				continue;
			}
			s&=a[k];
		}
		if(s>ans){
			ans=s;
		}
	}
	cout<<ans;
	return 0;
}
