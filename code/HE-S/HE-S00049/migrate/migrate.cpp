#include <bits/stdc++.h>
using namespace std;
const int MaxN=2e6+5;
int n,c,t,d,dd,cnt,cnt1[MaxN],setpw,ans=1;
int a[MaxN];
bool flag[MaxN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	
for(int oo=0;oo<t;oo++){
	memset(cnt1,0,sizeof(cnt1));
	memset(a,0,sizeof(a));
	cin >> n >> d;
	dd=d;
	for(int i=0;i<n;i++){
		cin >> a[i];
		flag[a[i]]=1;
	}
	
	while(dd>0){
		for(int i=0;i<n;i+=setpw){
			for(int j=dd;j>=1;j--){
				if(!flag[a[i]+j]) continue;
				cnt1[cnt]++;
				setpw=j;
				break;
			}
				
		}
		cnt++;
		dd--;
	}
	sort(cnt1,cnt1+cnt);
	for(int i=0;i<cnt;i++){
//		cout << cnt1[i] << " ";
		if(cnt1[0]==0){
			ans=1;
			break;
		}
		if(cnt1[i]==cnt1[i+1]) ans++;
		else break;
	}
//	cout << endl;
	cout << ans << endl;
} 




	return 0;
}
