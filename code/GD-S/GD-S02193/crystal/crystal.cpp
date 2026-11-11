#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n,max2=0;
long long l;
bool flag=0;
void heti(vector<long long> a,int i){
	int j=1;
	if(!flag){
		j=0;
	}
	int cnt=0;
	long long m=l;
	while(i>=j&&m>0){
		if((a[i]-a[i-j])<=m){
			m=m-(a[i]-a[i-j]);
			a[i-j]=a[i];
			cnt++;
		}
		j++;
	}
	if(cnt+1>max2){
		max2=cnt+1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	vector<long long> z;
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		long long c;
		cin>>c;
		z.push_back(c);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(z[i]>z[j]){
				swap(z[i],z[j]);
			}
		}
	}
	long long cha=z[1]-z[0];
	for(int i=2;i<n;i++){
		if(z[i]-z[i-1]!=cha){
			flag=1;
			break;
		}
	}
	if(cha==1){
		flag=1; 
	}
	int i=1;
	if(!flag){
		i=0;
	}
	for(;i<n;i++){
		heti(z,i);
	}
	cout<<max2;
	return 0;
} 
