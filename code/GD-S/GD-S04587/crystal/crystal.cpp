#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n,a[500005],m,mm=0;	
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		int nnn=0,cnt=0;
			for(int  i=1;i<=n;i++){
				if(a[j]>=a[i]&&a[i]!=0){
					nnn+=a[j]-a[i];
					if(nnn>m){
						mm=max(mm,cnt);
						continue;
					}
				cnt+=1;
				}
			}
			mm=max(mm,cnt);
		}
	cout<<mm;
	return 0;
}
