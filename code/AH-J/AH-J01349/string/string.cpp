#include<bits/stdc++.h>
using namespace std;
int n,l,ll,a[666666],s=1,ans=0,c=s/2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;++i){
		cin >>l>>ll;
		for(int j=1;j<=l;++j){
			a[s]=ll;
			s++;
		}
	}
	for(int i=1;i<=c;++i){
		if(a[i]==a[s])ans++;
	}
	if(n=1){cout <<0;
	}else{
	cout <<s;
	}
	return 0;
} 
