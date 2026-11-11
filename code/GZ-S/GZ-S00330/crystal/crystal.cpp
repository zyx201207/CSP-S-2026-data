//GZ-S00330 贵州省铜仁第一中学 李宇烜
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,ans=1;
int l=1,r=1;
long long m,sum,cnt,a[N],c[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c[i] = a[i+1] - a[i];
	}
	sum = 0;
	for(int i=1;i<n;i++){
		if(r <= n){
			if(sum <= m){
				ans = max(ans,r-l+1);
				r++;
				sum = sum+(r-l)*c[r-1];		
			}
			else{
				for(int i=l;i<r;i++)
					cnt += c[i];
				sum = sum-cnt;
				cnt = 0;
				l++;
				r++;
				sum = sum+(r-l)*c[r-1];
			}
		}
		else
			break;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}
