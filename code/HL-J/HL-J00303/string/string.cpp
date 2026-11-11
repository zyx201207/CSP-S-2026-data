#include<bits/stdc++.h>
using namespace std;
    long long n,sum=0,ans=0;
    int a[300000];
    char a1[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i]>>a1[i];
	}
	string s;
	for(int i=0;i<n;i++){
		sum+=a[i];
		for(int j=0;j<a[i];j++)
		s+=a1[i];
	}
	int l=0,r=sum-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
