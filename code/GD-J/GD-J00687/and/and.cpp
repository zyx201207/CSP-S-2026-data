#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m,cnt,cnt1;
long long a[N],s1[N],s2[N],ans,mx=-1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			cnt=0;cnt1=0;ans=0;
			while(a[i]>0){
				cnt++;
				s1[cnt]=a[i]%2;
				a[i]/=2;
			}
			while(a[i-1]>0){
				cnt1++;
				s2[cnt1]=a[i-1]%2;
				a[i-1]/=2;
			}		
			for(int i=1;i<=cnt;i++){
				if(s1[i]==1 && s2[i]==1)ans+=pow(2,i-1);
				s1[i]=0;s2[i]=0;
			}
			a[i]=ans;
		}
	}
	cout<<ans;
	return 0;
}
/*
16 8 4 2 1
1  1 1 1 1
0  1 1 1 1
0  0 1 1 1


3
3
31 15 7
*/
