//GZ-S00379 刘祚诚 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],m,ans;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=2;i--){
			int mm=m,sum=0,j=0;
			while(mm>0&&i-j>0){
				if(mm-a[i]+a[i-j]>=0){
					mm-=a[i];
					mm+=a[i-j];
					j++;
					sum++;
				}else{
					mm=0;
				}
			}
			if(sum>ans)ans=sum;
		}
		cout<<ans<<endl;	
	}else{
		for(int i=1;i<=10;i++){
			cin>>a[i];
		}	
		long long cha=a[2]-a[1];
		long long summ=1,mmm=m;
		while(mmm>0){
			long long q=summ*cha;
			if(mmm-q>=0){
				mmm-=q;
				summ++;
			}else{
				break;
			}
		}
		cout<<summ<<endl;	
	}

	return 0;
}

