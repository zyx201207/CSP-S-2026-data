#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	int num;
	char str;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,j,ans=0,l=0,tl=0;
	char a;
	cin>>n;
	j=n-1;
	st s[n];
	for(int i=0;i<n;i++){
		cin>>m>>a;
		s[i].num=m;
		s[i].str=a;
		l+=m;
	}
	for(int i=0;i<n;i++){
		int tmp=s[i].num;
		tl+=tmp;
		while(tmp>s[j].num){
			if(s[i].str!=s[j].str){
				ans+=s[j].num;
			}
			tmp-=s[j].num;
			j--;
		}
		if(s[i].str!=s[j].str){
			ans+=tmp;
			s[j].num-=tmp;
			tmp=0;
		}
		if(tl>=l/2){
			break;
		}
	}
	cout<<ans;
	return 0;
}

