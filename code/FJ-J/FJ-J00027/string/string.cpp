#include<bits/stdc++.h>
using namespace std;
struct c{
	int a;
	char p;
};
c s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,mid;
	long long int m=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].p;
		m+=s[i].a;
	}
	long long int sum=0,ans=0;
	int r=n-1;
    for(int i=0;i<n;i++){
    	sum+=s[i].a;
    	if(sum>=m/2){
    		mid=i;
    		break;
		}
	}
	for(int i=0;i<=mid;i++){
		if(s[i].a==s[r].a){
			if(s[i].p==s[r].p) r-=1;
			else{
				ans+=s[r].a;
				r-=1;
			}
		}
		else{
			if(s[i].a<s[r].a){
				if(s[i].p!=s[r].p) ans+=s[i].a;
				s[r].a-=s[i].a;
			}
			else{
				long long int su=s[r].a;
				if(s[r].p!=s[i].p) ans+=s[r].a;
				while(r>i&&su<=s[i].a){
					r-=1;
					su+=s[r].a;
					if(su>s[i].a){
						if(s[r].p!=s[i].p) ans+=s[i].a-su+s[r].a;
						s[r].a=su-s[i].a;
						break;
					}
					if(s[r].p!=s[i].p){
						ans+=s[r].a;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

