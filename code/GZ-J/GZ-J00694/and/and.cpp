//马浩然 六盘水市第一实验中学 GJ-J00694 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int *ans=new int[n+1];
	int *a=new int [n+1];
	/*while (i>0){
		cin>>a[i];
		ans[i]=a[i];
		ans[i]=ans[i]%2;
		n/2;
		i--;
		cout<<ans[i]<<'\n';
	}*/
	/**/
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]%2==0){
			ans[i]=0;
			n/2;
		}	
		if (a[i]%2==1){
			ans[i]=1;
			n/2;
		}
	}
	for (int i=1;i<=n;i++){
		for(int j=i+1;j<=n;i++){
			if (ans[i]>=ans[j]){
				ans[i]=ans[j];
			}
		}
	}
	cout<<*ans<<endl;
	delete [] ans;
	delete [] a;
	return 0;
}
