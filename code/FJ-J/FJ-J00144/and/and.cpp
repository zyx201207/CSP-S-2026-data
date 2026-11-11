/*Η ΠΟΛΗ ΕΠΕΣΕ, ΜΑ ΤΟ ΦΟΣ ΔΕΝ ΣΒΙΝΕΙ
Ο ΒΑΣΙΛΙΑΣ ΖΙ ΣΤΙΝ ΚΑΡΔΙΑ
ΦΥΛΑΚΕΣ ΠΙΣΤΗΣ ΚΕ ΔΟΞΑΣ
ΣΑΝ ΑΣΤΡΑΠΙ ΘΑ ΕΡΘΕΙ*/
#include<bits/stdc++.h>
using namespace std;
void rp(int rp){
	while(1)rp++;
}
int n,m,a[207891],b[207891];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)cin>>a[i];
	int ans=0;
	if(m==1)for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	if(m==2)for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
	if(m==3)for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)for(int k=j+1;k<=n;k++)ans=max(ans,a[i]&a[j]&a[k]);
	else{
		sort(a+1,a+n+1,greater<int>());
		ans=a[m-1];
	}
	cout<<ans<<endl;
	return 0;
}

