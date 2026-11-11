#include<bits/stdc++.h>
using namespace std;
int a[1000000010];
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		
	}
	
	int len=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			 s=c[i]+s;
		}
		 len=len+a[i];
	}
	int cnt=0;
     
	for(int i=0;i<=len-1;i++){
		for(int j=len-1;j>=i;j--){
			if(s[i]!=s[j]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	
	return 0;
}
