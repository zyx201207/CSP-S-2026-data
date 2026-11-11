#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[200010];
	unsigned long long T;
	cin>>T;
	unsigned long long srxb=0,mysize=0;
	for(unsigned long long i=0;i<T;i++){
        unsigned long long t;
        char cc;
        cin>>t>>cc;
        mysize+=t;
        while(t--){
            s[srxb]=cc;
            srxb++;
        }
	}
	unsigned long long ans=0;
	for(unsigned long long i=0;i<=mysize/2;i++){
        if(s[i]!=s[mysize-1-i])ans++;
	}
	//cout<<s[mysize-1];
	cout<<ans;
    return 0;
}
