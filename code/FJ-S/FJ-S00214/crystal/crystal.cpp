#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int n;
long long m;
int a[N];
long long h[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	int res=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			h[j]=abs(a[i]-a[j]);
		}

		sort(h+1,h+1+i);
		
		int k=1;
		long long mm=m;
		while(mm>=0){
			if(k>=i){
				k=i;
				break;
			}
			mm-=h[k];
			k++;
		}
		if(mm<0){
			k--;
		}
		if(k==i){
			k++;
		}
		res=max(res,k-1);
	}
	
	cout<<res<<"\n";
	
	return 0;
}
