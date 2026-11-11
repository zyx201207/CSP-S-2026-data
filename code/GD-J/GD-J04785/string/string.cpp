#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e5;
int n,ans;
struct p{
	char c;
	int a;
};
p s[M];
void cx(int i,int j){
	if(i==j){
		return ;
	} 
	if(s[i].c!=s[j].c){
		if(s[i].a>s[j].a){
		    int k=s[i].a-s[j].a;
			ans+=k;
			s[i].a=k;
			cx(i,j-1);
		}else if(s[i].a<s[j].a){
			int k=s[j].a-s[i].a;
			ans+=k;
			s[j].a=k;
			cx(i+1,j);
		}else if(j-i==1){
			return ;
		}else cx(i+1,j+1);
	}else{
		if(s[i].a>s[j].a){
		    int k=s[i].a-s[j].a;
			s[i].a=k;
			cx(i,j-1);
		}else if(s[i].a<s[j].a){
			int k=s[j].a-s[i].a;
			s[j].a=k;
			cx(i+1,j);
		}else if(j-i==1){
			return ;
		}else cx(i+1,j+1);
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	cx(1,n);
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a
*/
