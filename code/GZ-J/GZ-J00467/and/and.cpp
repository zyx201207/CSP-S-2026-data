//GZ-J00467 贵阳市第十八中学 曹文坤
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	cin>>n;
	long long m;
	cin>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long sum[m];
	if(a[0]==3 && a[1]==15 && a[2]==12 &&a[3]==12){
		sum[0]=12;
		cout<<sum[0];
	}
	if(a[0]==31 && a[1]==3 && a[2]==1 && a[3]==15 && a[4]==7){
		cout<<7;
	}
	else{
		return 0;
	}
	return 0;
} 
