#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long> a;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int sum=0;
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		int x=m,num=1;
		vector<long long> b;
		b=a;
		int j;
		for(j=mid-1;j>=0&&x>0;){
			if(b[j]<b[mid]){
				b[j]++;
				x--;
			}
			if(b[j]==b[mid]){
				num++;
				j--;
			}
		}
		while(a[mid+1]==a[mid]&&mid+1<n){
			mid++;
			num++;
		}
		num++;
		sum=max(sum,num);
		if(x==0&&j==-1){
			cout<<sum;
			return 0;
		}
		if(j==-1&&x>0){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<sum;
	return 0;
}
