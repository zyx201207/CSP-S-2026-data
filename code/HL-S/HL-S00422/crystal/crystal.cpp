#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[500010],b[99999]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m1,cnt=0;
	long long m;
	cin>>n>>m;
	m1=m;
	for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(m1>=a[i]-a[j]){
				m1-=a[i]-a[j];
				b[i]++;
			}else{
				break;
			}
		}
		m1=m;
	}
	sort(b,b+n,cmp);
	cout<<b[0]+1;
	return 0;
}