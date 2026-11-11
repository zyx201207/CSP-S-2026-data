#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l[200005],sum,num,ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>c[i];
		sum+=l[i];
	}
	if(sum%2==1){
		sum=(sum+1)/2;
		int w;
		for(w=1;w<=n;w++){
			num+=l[w];
			if(num>sum){
				break;
			}
		}
		for(int i=n;i>=w+1;i--){
			l[i+1]=l[i];
			c[i+1]=c[i];
		}
		l[w+1]=num-sum;
		c[w+1]=c[w];
		l[w]=l[w]-l[w+1]-1;
		int inx=w+1;
		for(int i=w;i>=1;i--){
			while(l[i]){
				if(l[i]>l[inx]){
					if(c[i]!=c[inx]){
						ans+=l[inx];
					}
					l[i]-=l[inx];
					l[inx]=0;
					inx++;
				}
				else{
					if(c[i]!=c[inx]){
						ans+=l[i];
					}
					l[inx]-=l[i];
					l[i]=0;
					if(l[inx]==0){
						inx++;
					}
				}
			}
		}
	}
	else{
		sum=sum/2;
		int w;
		for(w=1;w<=n;w++){
			num+=l[w];
			if(num>sum){
				break;
			}
		}
		for(int i=n;i>=w+1;i--){
			l[i+1]=l[i];
			c[i+1]=c[i];
		}
		l[w+1]=num-sum;
		c[w+1]=c[w];
		l[w]=l[w]-l[w+1];
		int inx=w+1;
		for(int i=w;i>=1;i--){
			while(l[i]){
				if(l[i]>l[inx]){
					if(c[i]!=c[inx]){
						ans+=l[inx];
					}
					l[i]-=l[inx];
					l[inx]=0;
					inx++;
				}
				else{
					if(c[i]!=c[inx]){
						ans+=l[i];
					}
					l[inx]-=l[i];
					l[i]=0;
					if(l[inx]==0){
						inx++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
