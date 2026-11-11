#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
char s[999999999];
long long len=1,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]--){
			s[len]=c[i];
			len++;
		}
    }
	for(int i=1;i<=len;i++){
		if(s[i]!=s[len+1-i]){
			sum++;
		}
	}
	cout<<sum-2;
	return 0;
}

