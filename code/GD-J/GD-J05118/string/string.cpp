#include<bits/stdc++.h>
using namespace std;
struct duan{
	long long a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	duan s[n+5];
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	long long l=0,r=n-1;
	while(l<r){
		if(s[l].c!=s[r].c){
			if(max(s[l].a,s[r].a)-min(s[l].a,s[r].a)!=0){
				ans+=max(s[l].a,s[r].a)-min(s[l].a,s[r].a);
			}else{
				ans+=s[l].a;
			}
			
		}
		if(s[l].a>s[r].a){
			s[l].a-=s[r].a;
			r--;
		}else{
			s[r].a-=s[l].a;
			l++;
			if(s[r].a==0) r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

