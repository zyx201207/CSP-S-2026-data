#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long ans=0;
	long long s[200005];
	char s1[200005];
	for(long long i=1;i<=n;i++){
		cin>>s[i];
		cin>>s1[i];
	}
	long long t,h=1,m=s[n],flag=0;
	t=n;
	while(t>=h){
		if(s1[t]==s1[h]){
			if(flag==0){
				if(m>=s[h]){
					m=m-s[h];
					h++;
				}
				else{
					m=s[h]-m;
					flag=1;
					t--;
				}
			}
			else{
				if(m>=s[t]){
					m=m-s[t];
					t--;
				}
				else{
					m=s[t]-m;
					flag=0;
					h++;
				}
			}
		}
	    else{
			if(flag==0){
				if(m>=s[h]){
					m=m-s[h];
					ans+=s[h];
					h++;
				}
				else{
					ans+=m;
					m=s[h]-m;
					flag=1;
					t--;
				}
			}
			else{
				if(m>=s[t]){
					m=m-s[t];
					ans+=s[t];
					t--;
				}
				else{
					ans+=m; 
					m=s[t]-m;
					flag=0;
					h++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
