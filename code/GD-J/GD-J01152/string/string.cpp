#include<bits/stdc++.h>
#define tt long long
using namespace std;
tt n,a[200005],ans;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(tt i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	tt l=1,r=n,l1=a[l],r1=a[r];
	while(l<r){
		if(l1<r1){
			r1-=l1;
			if(c[l]!=c[r])ans+=l1;
			l++;
			l1=a[l];
		}
		else if(l1>r1){
			l1-=r1;
			if(c[l]!=c[r])ans+=r1;
			r--;
			r1=a[r];
		}
		else{
			if(c[l]!=c[r])ans+=r1;
			l++,r--;
			l1=a[l],r1=a[r];
		}
	}
	cout<<ans;
}
