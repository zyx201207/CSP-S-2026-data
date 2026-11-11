#include<bits/stdc++.h> 
using namespace std;
long long a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int n;
	cin>>n>>m;
	bool flag=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=0&&i>2){
			if(abs(a[i+1]-a[i])==(abs(a[1]-a[0]))&&!flag){
				flag=false;
			}else{
				flag=true;
			}
		}
	}
	int b;
	if(!flag){
		b=a[1]-a[0];
	}
	if(!flag){
		int e=m;
		int i=b;
		int sum=1;
		while(e!=0){
			e-=i;
			i+=(sum*b);
			sum++;
		}
		cout<<sum-1<<endl;
		return 0;
	}
	sort(a,a+n);
	int ans=0;
	for(int i=1;i<n;i++){
		int k=1;
		long long w=a[i];
		long long r=m;
		for(int j=i-1;j>=0;j--) {
			if(r-(w-a[j])>=0){
				r-=(w-a[j]);
				k++;
			}else{
				break;
			}
		}
		if(ans<k){
			ans=k;
		}
	}
	cout<<ans<<endl;
	return 0;
}

