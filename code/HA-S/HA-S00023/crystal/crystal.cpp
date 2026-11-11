#include<bits/stdc++.h>
using namespace std;
long long n,m,num,maxn=INT_MIN,a[100005],b[100005]; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		
		num=a[i];
		int cnt=m,sum=1;
		
		for(int k=0;k<n;k++) b[k]=a[k];
		
		for(int j=i+1;j<n;j++){	
			if(cnt<=0) break;
			while(b[j]<a[i]&&cnt>0) {
				b[j]++;
				cnt--;
			} 
			sum++;
		}
		
		if(sum>maxn) maxn=sum;
		
	}
	cout<<maxn;
	return 0;
}
