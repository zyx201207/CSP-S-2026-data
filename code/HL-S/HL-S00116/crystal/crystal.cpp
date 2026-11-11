#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],num,am,ans=INT_MIN,j2;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>am;
	for(int i=0;i<n;i++) cin>>b[i];
	sort(b,b+n);
//	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	for(int i=1;i<n;i++){//ding ji zhun
	    m=am;
	    for(int k=0;k<n;k++) a[k]=b[k];
//	    printf("本次标准为第%d项，大小为%d\n",i+1,a[i]);
		for(int j=i-1;j>=0;j--){
			while(a[i]!=a[j]){
				a[j]++;
				m--;
//				printf("将第%d项由%d变为%d,m变为%d\n",j+1,a[j]-1,a[j],m);
				if(m==0) break;
			}
			if(m==0||a[0]==a[i]){
				j2=j;
				if(a[j]==a[i]) j2--;
		    	break;
			}
		}
		if(ans<i-j2) ans=i-j2;
//		cout<<i<<" "<<j2;
	}
	cout<<ans;
	return 0;
}
