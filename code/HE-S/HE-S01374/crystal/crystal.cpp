#include<bits/stdc++.h>
using namespace std;
const long long N=1e12+1;
long long n,m,a[N],cnt=1,num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<m){
				cnt++;
			}else{
				break;
			}
		}
		num=max(num,cnt);
	}
	cout<<num;
	return 0;
}
