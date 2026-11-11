#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],stu[33],ji[33][200005],er[33],ans,cun[200005],need,lin;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	er[0]=1;
	for(int i=1;i<=30;i++) er[i]=er[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cun[i]=a[i];
	}
	need=30;
	while(need>-1){
		lin=-1;
		memset(stu,0,sizeof(stu));
		memset(ji,0,sizeof(ji));
		for(int i=1;i<=n;i++){
			for(int ii=0;ii<=need;ii++){
				if((cun[i]&(1<<ii))!=0){
					stu[ii]++;
					ji[ii][i]=1;
				}
			}
		}
		memset(cun,0,sizeof(cun));
		for(int i=need;i>=0;i--){
			if(stu[i]>=m) lin=max(lin,i);
		}
		if(lin!=-1){
			ans+=er[lin];
		}
		else break;
		for(int i=1;i<=n;i++){
			if((a[i]&(1<<lin))!=0){
				cun[i]=a[i];
			}
		}
		need=lin-1;
	}
	cout<<ans;
}
