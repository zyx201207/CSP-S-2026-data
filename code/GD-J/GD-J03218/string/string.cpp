#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n=0,cd=0,xg=0;
	string da="";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
		cd+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			da+=s[i];
		}
	}
	if(cd%2==0){
		for(int h=1;h<=cd/2;h++){
			if(da[h-1]!=da[cd-h]){
				xg+=1;
			}
		}
	}
	else{
		for(int h=0;h<cd/2;h++){
			if(da[h]!=da[cd-1-h]){
				xg+=1;
			}	
		}
	}

	cout<<xg;

	return 0;
}

