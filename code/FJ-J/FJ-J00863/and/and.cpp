#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n-m+2;j++){
			int o=a[i],t=a[j],l_=1,ans_=0;
			for(int l=j;l<=j+m-2;l++){
				t=a[l];
				ans_=0;
				while(o!=0&&t!=0){
					int o_=o%2,t_=t%2;
					if(o_==t_)ans_+=o_*l_;
					l_=l_*2;
					o=o/2;
					t=t/2;
				}
				o=ans_;
				l_=1;
			}
			if(ans_>=ans)ans=ans_;
		}
	}
	cout<<ans;
	return 0;
}

