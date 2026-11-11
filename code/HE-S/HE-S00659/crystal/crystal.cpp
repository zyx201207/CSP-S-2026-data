#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,c=0;
long long a[500500];
bool aaa(long long x){
	long long mg=m;
	c=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			mg=mg-x+a[i];
			c++;
		}
		else break;
	}
	if(mg>=0) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n];
	long long mid=(l+r)/2;
	while(l<=r){
		//cout<<"µ±Ç°mid:"<<mid<<endl; 
		if(aaa(mid)){
			l=mid+1;
			cnt=max(cnt,c);
			//cout<<"ok  c:"<<c<<" cnt:"<<cnt<<endl;
		}
		else{
			r=mid-1;
			//cout<<"no"<<endl;
		}
		mid=(l+r)/2;
	}
	cout<<cnt;
	return 0;
} 
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
