#include<bits/stdc++.h>
using namespace std;
int n;
long long m_1,ans_max;
vector<int> a;
vector<int> b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m_1;
	for(int i=1;i<=n;i++){
		int ppp;
		scanf("%d",&ppp);
		a.push_back(ppp); 
		b.push_back(ppp);
	}
	int as=a.size();
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int k=a[0];k<=a[as-1];k++){
		long long ans=0;
		long long m=m_1;
		for(int i=0;i<n;i++) b[i]=a[i];
		for(int i=0;i<n;i++){
			long long c_min=LONG_LONG_MAX;
			long long cha=0;
			int xb=-1;
			for(int j=0;j<n;j++){
				if(b[j]<=k){
					cha=k-b[j];
					if(cha<0) cha=cha-2*cha;
					if(cha<c_min){
						c_min=cha;
						xb=j;
					}
				}
			}
			m-=c_min;
			if(m>=0){
				b[xb]=INT_MAX;
				ans++;
			}else break;
			if(m==0) break;
			
		}
		if(ans>ans_max) {
			ans_max=ans; 
		}
	}
	cout<<ans_max;
	return 0;
}
