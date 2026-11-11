#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
bool b[N];
int found(int t){
	int min_=1e9,min_i=0; 
	for(int i=1;i<=n;i++){
		if(a[t]-a[i]<min_&&a[t]-a[i]>=0&&b[i]==false){
			min_=abs(a[t]-a[i]);
			min_i=i; 
		}
	} 
	b[min_i]==true;
	return min_i;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int max_=-1,ji=0;
	for(int i=1;i<=n;i++){
		int ma=m;
		for(int j=1;j>=1;j++){
			int min_i=found(i);
			if(ma-(a[i]-a[min_i])>=0){
				ma-=(a[i]-a[min_i]);
				ji++;
			}else{
				continue;
			}
			
			if(j>n){
				break;
			}
		}
		if(ji>max_){
			max_=ji;
		}
		for(int j=1;j<=n;j++){
			b[j]=false;
		} 
	}
	cout<<max_;
	return 0;
} 
