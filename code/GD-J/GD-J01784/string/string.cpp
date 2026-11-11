#include<bits/stdc++.h>
using namespace std;
#define int long long
struct S{
	int m;
	char s;
}str[200050];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int num;
	cin>>num;
	for(int i=1;i<=num;i++){
		cin>>str[i].m>>str[i].s;
	}
	int l=1,r=num,ans=0;
	while(l<=r){
		if(str[l].m==str[r].m){
			if(str[l].s!=str[r].s){
				ans+=str[l].m;
			}
			l++;
			r--;
		}else if(str[l].m>str[r].m){
			if(str[r].s!=str[l].s){
				ans+=str[r].m;
			}
			str[l].m-=str[r].m;
			r--;
		}else{
			if(str[l].s!=str[r].s){
				ans+=str[l].m;
			}
			str[r].m-=str[l].m;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
