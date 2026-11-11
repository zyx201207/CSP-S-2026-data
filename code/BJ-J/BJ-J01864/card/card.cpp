#include<bits/stdc++.h>
using namespace std;
long long n,m,pfora=1;
long long a[500005],ans[300005],c[500005],mimi,form[20];
map<int,int>maxi;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=-2e10;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxi[a[i]]++;
		if(maxi[a[i]]==1)mimi++;
		if(mimi<10){
			form[mimi]=a[i];
		}
		if(!(a[i]>=a[i-1])){
			pfora=0;
		}
	}
	if(mimi==2){
		int ans1,ans2;
		ans1=ans2=0;
		for(int o=1;o<=n;o++){
			int p1=a[o],p2=a[n],p3=form[1],p4=form[2];
			if(p1==p3&&p2==p3){
				ans1++;
			}
			else if(p1==p4&&p2==p4){
				ans2++;
			}
			else if(p1==p3&&p2==p4){
				ans1++;
				ans2++;
			}
			else if(p1==p4&&p2==p3){
				ans1++;
				ans2++;
			}
		}
		cout<<ans1<<" "<<ans2;
		return 0;
	}
	else if(pfora){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		for(int o=1;o<=n;o++){
			int cnt=0;
			map<int,int>mp;
			for(int i=o;i<=n;i++){
				if(!mp[a[i]]||mp[a[i]]>cnt||c[mp[a[i]]]!=a[i]){
					c[++cnt]=a[i];
					mp[a[i]]=cnt;
				}
				else{
					cnt=mp[a[i]];
				}
			}
			for(int i=1;i<=cnt;i++){
				ans[c[i]]++;
//				cout<<c[i]<<" ";
			}
//			cout<<endl;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
