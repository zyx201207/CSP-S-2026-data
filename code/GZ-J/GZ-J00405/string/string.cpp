//GZ-J00405 华东师范大学附属贵阳学校 刘凌舟 
#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int x;
	char c;
	for (int i=1;i<=n;i++){
		cin>>x>>c;
		a[i]=x;
		b[i]=c;
	}
	int h=1,t=n;
	long long ans=0;
	while (h<t){
		if (b[h]==b[t]){
			if (a[h]==a[t]){
				h++,t--;
			}
			else if (a[h]>a[t]){
				a[h]=a[h]-a[t];
				t--;
			}
			else{
				a[t]=a[t]-a[h];
				h++;
			}
		}else{
			if (a[h]==a[t]){
				ans+=a[h];
				h++,t--;
			}
			else if (a[h]>a[t]){
				a[h]=a[h]-a[t];
				ans+=a[t];
				t--;
			}
			else{
				a[t]=a[t]-a[h];
				ans+=a[h];
				h++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
