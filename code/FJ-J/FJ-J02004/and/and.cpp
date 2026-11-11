#include<bits/stdc++.h>
using namespace std;
int a[200005],f[200005][31];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int mnc=a[i];
		for(int j=1;j<=30;j++){
			f[i][31-j]=mnc%2;
			mnc/=2;
			if(mnc==0)break;
		}					//转二进制 
	}
	/*for(int i=1;i<=n;i++){
			for(int j=0;j<=30;j++){
				cout<<f[i][j]<<' ';
			}
			cout<<endl;
		}				*/			
	long long ans=0;
	for(int i=1;i<=30;i++){		//每个数位循环 
		int s=0;				
		for(int j=1;j<=n;j++){
			if(f[j][i]==1&&f[j][0]!=-1)s++;	
		}					//判断有多少个数此位是1 
		if(s>=m){			//有大于m个数，其他数标记-1;ans加上与的结果 
			for(int j=1;j<=n;j++){
				if(f[j][i]==0)f[j][0]=-1;
				ans+=pow(2,28-i);
			}
		} if(s==m){		//等于，所有数直接算 &  
			ans=pow(2,31)-1;
			for(int j=1;j<=n;j++){
				if(f[j][0]==0)ans =ans & a[j];
			}
			cout<<ans;
			return 0;
		}
	}
	/*for(int j=1;j<=n;j++){
			cout<<f[j][0]<<' ';
		}*/ 
	cout<<ans;
	return 0;
}

