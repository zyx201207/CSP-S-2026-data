#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	int n;
 	cin>>n;
 	string s1;//±íÊ¾×Ü 
	for(int i=0;i<n;i++){
		int a;
		string s;
		cin>>a>>s;
		for(int j=0;j<a;j++){
			s1+=s;
		}
	} 
	int l=0,r=s1.size();
		int mid=(l+r)/2;
		int sum=0;
		for(int i=0;i<mid;i++){
			if(s1[i]!=s1[r-i-1]){
				sum++;
			}
		}
		cout<<sum;
} 
