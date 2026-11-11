#include<bits/stdc++.h>
using namespace std;
string s=" ";
long long n,m=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        char b;
        cin>>a>>b;
        m+=a;
        for(long long j=1;j<=a;j++){
            s+=b;
        }
    }
    for(long long i=1,j=m;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans<<endl;
}
