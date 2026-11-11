#include<bits/stdc++.h>
using namespace std;
int main(){
	//GZ-J00037,贵阳市观山湖外国语实验中学,张汉琦 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m=0;
	cin>>n;
	int a[200000]={0};
	string b;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=0,r=n;
	while(1){
		//cout<<1;
		if(b[l]!=b[r]){
			m=m+min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]=a[l]-a[r]; a[r]=0;
				r--;
			} else if(a[l]<a[r]){
				a[r]=a[r]-a[l]; a[l]=0;
				l++;
			}else{
				a[l]=0; a[r]=0;
				l++; r--;
			}
		}
		else if(b[l]==b[r]){
			l++; r--;
		}
		if(l>=r){
			break;
		}
	}
	cout<<m;
	return 0;
}
