#include<bits/stdc++.h> 
using namespace std;
long long a[200011];
char c[200011];
string s;
long long num,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		} 
	}
	for(int i=0;i<num/2;i++){
        if(s[i]!=s[num-i-1])
            ans++;
	}
    cout<<ans;
	return 0;
}
