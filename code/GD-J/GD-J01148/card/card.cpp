#include<bits/stdc++.h>
using namespace std;
int a[500005],t2[300005];
int sum1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		int t1[300005]={0};
		int sum=0;
		for(int j=i;j<n;j++){
			if(t1[a[j]]==0){
				t1[a[j]]++;
				sum++;
			}
			else{
				sum=0;
			}
		}
		sort(t1,t1+sum);
		for(int j=sum-1;j>=0;j++) t2[t1[j]]++;
		sum1+=sum;
	}
	sort(t2,t2+sum1);
	for(int i=m;i>=0;i--) cout<<t2[i]<<" ";
	return 0;
}
