//GZ-S00380 贵阳市新世界学校 孙熙锐 
#include<bits/stdc++.h>
using namespace std;
int c,T;
const int N=80;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long n,m,a[N],k=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n-m;i++){
			for(int j=i;m<j<=n;j++){
				if(abs(a[i]-a[j])==3)k++;
			}
		}
		cout<<k<<endl;
			
		
	}
	
	
	
	
	return 0;
}
