#include<bits/stdc++.h>
using namespace std;
#define int long long
struct S{
	char letter;
	int num=0;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	S s[n];
	for(int i=0;i<n;i++){
		cin>>s[i].num>>s[i].letter;
	}
	int l=0,r=n-1;
	while(l<r){
		if(s[l].letter==s[r].letter){
			if(s[l].num!=s[r].num){
				int m=min(s[l].num,s[r].num);
				s[l].num-=m;
				s[r].num-=m;
				if(s[l].num==0){
					l++;
				}else{
					r--;
				}
			}
		}else{
			if(s[r].num<s[l].num){
				ans+=s[r].num;
				s[l].num-=s[r].num;
				r--;
			}else{
				ans+=s[l].num;
				s[r].num-=s[l].num;
				if(s[r].num==0){
					r--;
				}
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
