//GZ-J00049 贵阳市第一中学 吴昊然 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans=0;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int t=1,w=n,tl=0,wl=0;
	while(t<w){
		int a1=a[t]-tl,a2=a[w]-wl;
		if(a1<a2){
			if(c[t]!=c[w])ans+=a1;
			wl+=a1;
			tl=0;
			t++;
		}else if(a1>a2){
			if(c[t]!=c[w])ans+=a2;
			tl+=a2;
			wl=0;
			w--;
		}else{
			if(c[t]!=c[w])ans+=a1;
			tl=0,wl=0;
			t++,w--;
		}
	}
	cout<<ans;
	return 0;
}
