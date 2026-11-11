#include<bits/stdc++.h>
using namespace std;
ios::sync_with_stdin(0);
cin.tie(0);cout.tie(0);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,po[600000],ans=0,now=0,left=0,c=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>po[i];
	sort(po,po+n);
	for(int i=0;i<n;i++){
		if(now+ans*(po[i]-po[i-1])<=m) now+=ans*(po[i]-po[i-1]),ans++;
		else{
			while(now+ans*(po[i]-po[i-1])>m){
				now-=po[i-1]-po[left];
				left++,ans--;
			}	
			now+=ans*(po[i]-po[i-1]),ans++;
		}
		c=max(c,ans);
	}
	cout<<c;
	return 0;
}
