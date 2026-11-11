#include <bits/stdc++.h>
using namespace std;
#define int long long
struct pai{
	int num;
	char st;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	pai s[n+2];
	for(int i=0;i<n;i++){
		int nums;
		char str;
		cin>>nums>>str;
		s[i].num=nums;
		s[i].st=str;
	}
	int ans=0;
	for(int i=0,j=n-1; i<n and j>=0 and i<j;){
		if(s[i].st==s[j].st){
			if(s[i].num==s[j].num){
				i++;
				j--;
			}
			else if(s[i].num>s[j].num){
				s[i].num-=s[j].num;
				j--;
			}
			else{
				s[j].num-=s[i].num;
				i++;
			}
		}
		else{
			if(s[i].num==s[j].num){
				ans+=s[i].num;
				i++;
				j--;				
			}
			else if(s[i].num>s[j].num){
				ans+=s[j].num;
				s[i].num-=s[j].num;
				j--;
			}
			else{
				ans+=s[i].num;
				s[j].num-=s[i].num;
				i++;
			}			
		}
		
	}
	cout<<ans;
	return 0;
}