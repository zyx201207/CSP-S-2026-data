#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e6+1; 
long long num[N],cnt=0;
char st[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cnt+=num[i];
		cin>>st[i];
	}
	long long tmp=0;
	long long l=1,r=n;
	long long all=0;
	while(l<=r){
		if(l==r&&n%2==1){
			break;
		} 
		if(st[l]==st[r]){
			if(num[l]>num[r]){
				num[l]=num[l]-num[r];
				num[r]=0;
				r--;
			}else if(num[l]<num[r]){
				num[r]=num[r]-num[l];
				num[l]=0;
				l++;
			}else{
				num[r]=0;
				num[l]=0;
				l++;
				r--;
			}
		}else if(st[l]!=st[r]){
			if(num[l]>num[r]){
				all+=num[r];
				num[l]=num[l]-num[r];
				num[r]=0;
				r--;
			}else if(num[l]<num[r]){
				all+=num[l];
				num[r]=num[r]-num[l];
				num[l]=0;
				l++;
			}else{
				all+=num[l];
				num[r]=0;
				num[l]=0;
				l++;
				r--;
			}
		}
	}
	cout<<all;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
