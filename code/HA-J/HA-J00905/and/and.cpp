#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(m==1){
		for(int i=0;i<n;i++){
			a[i]>max?max=a[i]:max=max;
		}cout<<max;
		return 0;
	}if(m==n){
		max=a[0];
		for(int i=1;i<n;i++){
			max=max&a[i];
		}cout<<max;
		return 0;
	}if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=a[i]&a[j];
				max<ans?max=ans:max=max;
			}
		}cout<<max;
		return 0;
	}if(m==n-1){
		int ans=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(i!=j)ans=ans&a[i];
			}if(ans>max)max=ans;
		}cout<<max;
		return 0;
	}
	
	int cnt[m];
	int ans=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
	for(int i=0;i<m;i++){
		cnt[i]=i;
	}
	while(cnt[m-1]!=m){
		for(int i=0;i<m-1;i++){
			if(cnt[i]>=m){
				cnt[i+1]++;
				cnt[i]=0;
			}if(cnt[i]==cnt[i+1]){
				cnt[i]++;
			}
		}for(int i=0;i<m;i++){
			ans=ans&a[cnt[i]];
		}if(ans>max)max=ans;
		cnt[0]++;
	}cout<<max;
	return 0;
}
