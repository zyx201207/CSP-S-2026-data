#include<bits/stdc++.h>
using namespace std;
long long n,s[200010],sum;
char q[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int y;
    cin>>n;
    for(y=0;y<n;y++) cin>>s[y]>>q[y];
	for(y=0;y<n/2;y++){
		if(q[y]!=q[n-y-1]){
			if(s[y]!=s[n-y-1]){
				if(s[y]<1&&s[n-y-1]<1) sum+=abs(s[y]-s[n-y-1])+1;
				else sum+=abs(s[y]-s[n-y-1]);
			} 
			else sum+=s[y];
		}
	}
	cout<<sum;
	return 0;
}
