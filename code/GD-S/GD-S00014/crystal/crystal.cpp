#include<bits/stdc++.h>
using namespace std;

int n,m,ans,maxn;
int a[100005];

bool cmp(int x,int y){
	return x<y;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(int i=n;i>=1;i--)
	{
		int sum=m;
		for(int j=i-1;j>1;j--)
		{
			if(sum-(a[i]-a[j]>=0)){
				sum-=a[i]-a[j];
				maxn++;
			}else{
				break;
			}
			
		}
		if(ans<maxn){
			swap(ans,maxn);
		}
		
	}
	cout << ans;
}

