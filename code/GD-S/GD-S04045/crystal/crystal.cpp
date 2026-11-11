#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],l,ans=1,cnt,t=1,h=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=a[1];
	for(int i=2;i<=n;i++){
		if(m>=(a[i]-l)*t){
			m-=(a[i]-l)*t;
			t++;
			ans=max(t,ans);
			l=a[i];
		}
		else{
			while(m<(a[i]-l)*t){
				m+=l-a[h++];
				t--;
			}
			if(t==0){
				l=a[i];
				t=1;
			}
			else{
				i--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
