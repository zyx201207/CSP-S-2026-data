#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long lenn1,ans,lenn2,cnt1,cnt2,lenn,sts;
string c[200005],s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		lenn+=a[i];
	}
	cnt2=n;
	while(lenn2<lenn/2){
		lenn2+=a[cnt1];
		cnt1++;
	}
	lenn2=lenn/2;
	cnt1-=1;
	sts=cnt1;
//	cout<<cnt1<<' '<<cnt2<<endl;
	if(lenn%2==0){
		while(cnt1>0&&cnt2>sts){
			if(a[cnt1]==a[cnt2]){
				if(c[cnt1]!=c[cnt2])ans+=a[cnt1];
				if(c[cnt1]==c[cnt2])ans+=0;
				cnt1-=1;
				cnt2-=1;
			}
			else{
				if(a[cnt1]>a[cnt2]){
					a[cnt1]-=a[cnt2];
					if(c[cnt1]==c[cnt2])ans+=0;
					if(c[cnt1]!=c[cnt2])ans+=a[cnt2];
					cnt2-=1;
				}
				if(a[cnt1]<a[cnt2]){
					a[cnt2]-=a[cnt1];
					if(c[cnt1]==c[cnt2])ans+=0;
					if(c[cnt1]!=c[cnt2])ans+=a[cnt1];
					cnt1-=1;
				}
			}
		}
		cout<<ans;		
	}
	if(lenn%2!=0){
		while(cnt1>0&&cnt2>sts){
			if(a[cnt1]==a[cnt2]){
				if(c[cnt1]!=c[cnt2])ans+=a[cnt1];
				if(c[cnt1]==c[cnt2])ans+=0;
				cnt1-=1;
				cnt2-=1;
			}
			else{
				if(a[cnt1]>a[cnt2]){
					a[cnt1]-=a[cnt2];
					if(c[cnt1]==c[cnt2])ans+=0;
					if(c[cnt1]!=c[cnt2])ans+=a[cnt2];
					cnt2-=1;
				}
				if(a[cnt1]<a[cnt2]){
					a[cnt2]-=a[cnt1];
					if(c[cnt1]==c[cnt2])ans+=0;
					if(c[cnt1]!=c[cnt2])ans+=a[cnt1];
					cnt1-=1;
				}
			}
		}
		cout<<ans;		
	}
	return 0;
}
