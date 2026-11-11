#include <bits/stdc++.h>
using namespace std;
int a[200005];
char flag[200005];
char s[200005][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=a[i],top=0;
		while(b!=0){
			if(b%2){
				s[i][top]='1';
			}else{
				s[i][top]='0';
			}
			top++;
			b/=2;
		}
//		cout<<s[i]<<endl;
		maxx=max(maxx,top-1);
	}
//	cout<<maxx<<endl;
	int f=0,t,p=0;
	for(int i=maxx;i>=0;i--){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1'&&!flag[j]){
				ans++;
			}
		}
//		cout<<ans<<endl;
		if(ans>=m){
			p=1;
			for(int j=1;j<=n;j++){
				if(s[j][i]!='1'){
					flag[j]=1;
				}
			}
		}else if(p){
			t=i;
			break;
		}
		f=ans;
	}
//	cout<<f<<endl;
	int k=1,sum=0;
	if(f==0){
		for(int i=1;i<=n;i++){
			if(!flag[i]){
				if(k){
					k=0;
					sum=a[i];
				}else{
					sum&=a[i];
				}
			}
		}
		cout<<sum;
		return 0;
	}
	if(f==m){
		for(int i=1;i<=n;i++){
			if(!flag[i]){
				if(k){
					k=0;
					sum=a[i];
				}else{
					sum&=a[i];
				}
			}
		}
	}else{
//		cout<<t<<endl;
		int l=0;
		for(int i=t;i>=0;i--){
			int ans=0;
			for(int j=1;j<=n;j++){
				if(s[j][i]=='1'&&!flag[j]){
					ans++;
				}
			}
			if(ans==m){
				for(int j=1;j<=n;j++){
					if(!flag[i]&&s[j][i]=='1'){
						if(k){
							k=0;
							sum=a[j];
						}else{
							sum&=a[j];
						}
					}
				}
				l=1;
				break;
			}
		}
		if(l==0){
			for(int i=1;i<=n;i++){
				if(!flag[i]){
					if(k){
						k=0;
						sum=a[i];
					}else{
						sum&=a[i];
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
