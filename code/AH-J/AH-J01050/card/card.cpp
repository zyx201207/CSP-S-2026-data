#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],cnt[500005],to;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>b[i];
	}
	for(long long i=0;i<n;i++){
		a[i]=b[i];
		long long t[500005]={0};
		for(long long j=i;j<n;j++){
			if(t[a[j]]==0){
				t[a[j]]++;
			}else{
				for(long long p=i;p<n;p++){
					if(a[p]==a[j]){
						to=p;
					}
				}
				for(long long p=to;p<j;p++){
					a[p]=0;
				}
			}
		}
		for(long long j=i;j<n;j++){
			cnt[a[j]]++;
		}
	}
	for(long long i=1;i<k;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<n;
	return 0;
}
