#include<bits/stdc++.h>
using namespace std;
string s[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0;
	char c;
	string s;
	cin>>n;
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j]
		}
	}
	for(int i=0;i<n;i++){
		int l=0,r=n;
		if(s[l]==s[r]){
			l++;
			r--;
			if(l==r || r-l==1){
				continue;
			}
		}else{
			sum++;
			l++;
			r--;
			if(l==r || r-l==1){
				continue;
			}
		}
	}	
	cout<<sum;
	return 0;
}
