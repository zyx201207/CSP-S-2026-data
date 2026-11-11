#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mp[5005];
int ans1=0,ans2=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int s1,s2=0;
	bool t=0;
	for(int i=1;i<=n;i++){
		cin>>s1;
		a[i]=s1;
		if(s1<s2){
			t=1;
		}
		s2=s1;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(t==0){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	int f=0,s=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[i]==1&&f==0){
					f=j;
				}else if(a[i]==2&&s==0){
					s=j;
				}else if(a[i]==1&&f!=0){
					if(s<j&&s>f){
						s=0;
					}
					f=j;
				}else if(a[i]==2&&s!=0){
					if(f<j&&f>s){
						f=0;
					}
					s=j;
				}
			}
			if(s!=0){
				ans2++;
			}
			if(f!=0){
				ans1++;
			}
			s=0;
			f=0;
		}
	}
	ans1+=ans2;
	cout<<ans1<<" "<<ans2;
	return 0;
}
