#include<bits/stdc++.h>
using namespace std;
long long n,k,lon,mid,ans;
char c;
string s,s1,s2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>c;
        lon+=k;
        for(int j=0;j<k;j++){
        	s=s+c;
		}
    }
   
    if(lon%2==1){
        mid=lon/2;
        for(long long i=mid-1;i>=0;i--){
        	s1=s1+s[i];
		}
        for(long long i=mid+1;i<=lon-1;i++){
        	s2=s2+s[i];
		}
		for(long long i=0;i<=mid-1;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
    }
    if(lon%2==0){
        mid=lon/2;
        for(long long i=mid-1;i>=0;i--){
        	s1=s1+s[i];
		}
        for(long long i=mid;i<=lon-1;i++){
        	s2=s2+s[i];
		}
		for(long long i=0;i<=mid-1;i++){
			if(s1[i]!=s2[i]){
				ans++;
			}
		}
    }
    cout<<ans;
    return 0;	
}
