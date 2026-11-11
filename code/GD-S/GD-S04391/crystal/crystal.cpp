#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[200005];
long long m,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=5001){
		sum=0;
		long long i=1;
		while(m-i>=0){
			sum++;
			m-=i;
			i++;
		} 
		if(sum>n)cout<<n;
		else cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	int x=-1;
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		if(x<b[a[i]])x=b[a[i]],maxx=i;
	}
	
	if(sum==1){
		for(int i=n;i>=1;i--){
			int maxn=1,mm=m,j=i;
			while(mm-(a[j]-a[j-1])>0&&j>1){
				mm=mm-(a[j]-a[j-1]);
				maxn++;
				j--;
			}
			if(sum<maxn)sum=maxn;
		} 
		cout<<sum;
		return 0;
	}else{
		for(int i=maxx,j=maxx+1;i>=1,j<=n;){
			if(a[maxx]-a[i]<a[j]-a[maxx]){
				if(a[maxx]-a[i]>m)break;
				else{
					m-=a[maxx]-a[i];
					sum++;
					i--;
				}
			}else{
				if(a[j]-a[maxx]>m)break;
				else{
					m-=a[j]-a[maxx];
					sum++;
					j++;
				}
			}
			cout<<sum<<' '<<m<<endl;
		}
	}
	cout<<sum;
	return 0;
}
