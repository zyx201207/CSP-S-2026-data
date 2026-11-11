#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,c[500001];
bool comp(int a,int b){
	return a>b;
}
void quicksort(int ll,int lr){
	if(ll>=lr){
		return;
	}
	int l=ll,r=lr;
	int mid=(c[l]+c[r])/2;
	while(l<r){
		while(c[l]>mid&&l<lr){
			l++;
		}
		while(c[r]<=mid&&r>ll){
			r--;
		}
		if(l<r){
			swap(c[l],c[r]);
		}
	}
	quicksort(ll,r);
	quicksort(r+1,lr);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	quicksort(0,n-1);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(n-1-i<=0){
			break;
		}
		long long t=1,r=m;
		for(int j=i+1;j<n;j++){
			if(r>=c[i]-c[j]){
				r=r-c[i]+c[j];
				t++;
			}
			else{
				break;
			}
		}
		ans=max(ans,t);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
